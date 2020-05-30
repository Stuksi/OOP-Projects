#include "..\Headers\Command_Prompt.h"

#include <algorithm>
#include <ctime>

bool CMD::exists(std::string file_name) {
    std::fstream file(file_name);
    return file.good();
}

bool CMD::empty_file(std::string file_name) {
    std::fstream file(file_name);
    return file.peek() == std::ifstream::traits_type::eof();
}

void CMD::open (std::ifstream& r_file, std::vector<Event>& events, std::string& file_name) {
    if(!r_file.is_open() && exists(file_name)) {
        r_file.open(file_name);
        if(!empty_file(file_name)){
            r_file >> events;
        }
        std::cout << file_name << " opened successfully!" << std::endl;
    } else {
        std::cout << file_name << " does not exist or is already opened!" << std::endl;
        file_name = "";
    }
}

void CMD::close (std::ifstream& r_file, std::vector<Event>& events, std::string& file_name) {
    if(r_file.is_open()) {
        events.clear();
        r_file.close();
        std::cout << file_name << " closed successfully!" << std::endl;
        file_name = "";
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CMD::save (std::ifstream& r_file, std::vector<Event>& events, std::string file_name) {
    if(r_file.is_open()) {
        std::ofstream w_file(file_name);
        w_file << events;
        w_file.close();
        std::cout << "Information saved successfully to " << file_name << "!" << std::endl;
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CMD::saveas (std::ifstream& r_file, std::vector<std::string> info_storage, std::vector<Event>& events) {
    if(r_file.is_open()) {
        if(!exists(info_storage[0])){
            std::ofstream w_file(info_storage[0]);
            w_file << events;
            w_file.close();
            std::cout << "Information saved successfully to " << info_storage[0] << "!" << std::endl;
        }else {
            std::cout << "The file name already exists!" << std::endl;
        }
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CMD::help () {
    
}

void CMD::add_event (std::vector<std::string> info_storage, std::vector<Event>& events) {
    Date date(info_storage[0]);
    for (size_t i = 0; i < events.size(); i++)
    {
        if(events[i].get_date() == date && events[i].get_hall().get_id() == stoi(info_storage[1])) {
            std::cout << "There's already another event at " << date << " in hall: " << info_storage[1] << std::endl;
            return;
        }
    }
    Hall new_hall(stoi(info_storage[1]));
    Event new_event (date, new_hall, info_storage[2]);
    events.push_back(new_event);
    std::cout << "Successfully created an event!" << std::endl;
}

void CMD::free_seats(std::vector<std::string> info_storage, std::vector<Event>& events) {
    std::ofstream event_reports("Event Reports.txt");
    Date date(info_storage[0]);
    bool in = false;
    for (size_t i = 0; i < events.size(); i++)
    {
        if(events[i].get_date() == date && events[i].get_name() == info_storage[1]) {
            in = true;
            events[i].event_report(0, event_reports);
            events[i].get_hall().print_hall();
        }
    }
    if (!in) {
        std::cout << "No movies whit that name on that date exist!" << std::endl;
    }
    event_reports.close();
}

void CMD::access_seats (std::vector<std::string> info_storage, std::vector<Event>& events, std::vector<int>& codes, int type) {
    Date date(info_storage[2]);
    bool in = false;
    int random_code;
    for (size_t i = 0; i < events.size(); i++)
    {
        if(events[i].get_date() == date && events[i].get_name() == info_storage[3]) {
            in = true;
            if(type == 2) {
                srand(time(NULL));
                do
                {
                    random_code = rand() % 10000 + 3;
                } while (std::count(codes.begin(), codes.end(), random_code));
                codes.push_back(random_code);
                events[i].update_hall_seat(random_code, stoi(info_storage[0]), stoi(info_storage[1]));
            } else {
                events[i].update_hall_seat(type, stoi(info_storage[0]), stoi(info_storage[1]));
            }
        }
    }
    if (!in) {
        std::cout << "No events whit that name on that date exist!" << std::endl;
    }
}

void CMD::bookings (std::vector<std::string> info_storage, std::vector<Event>& events) {
    std::ofstream event_reports("Event Reports.txt");
    if(info_storage.size() == 2) {
        Date date(info_storage[0]);
        bool in = false;
        for (size_t i = 0; i < events.size(); i++)
        {
            if(info_storage[1] == events[i].get_name() && date == events[i].get_date()) {
                in = true;
                events[i].event_report(1, event_reports);
            }
        }
        if (!in) {
            std::cout << "No events whit that name on that date!" << std::endl;
        }         
    } else if(info_storage.size() == 1) {
        Date date(info_storage[0]);
        bool in = false;
        for (size_t i = 0; i < events.size(); i++)
        {
            if(date == events[i].get_date()) {
                in = true;
                events[i].event_report(1, event_reports);
            }
        }
        if (!in) {
            std::cout << "No events on that date!" << std::endl;
        }
    } else if(info_storage.size() == 0) {
        for (size_t i = 0; i < events.size(); i++)
        {
            events[i].event_report(1, event_reports);
        }
        if (events.size() == 0) {
            std::cout << "No events to display information for!" << std::endl;
        }
    } 
    event_reports.close();
}

void CMD::check (std::vector<std::string> info_storage, std::vector<Event>& events, std::vector<int>& codes) {
    if(std::binary_search(codes.begin(), codes.end(), stoi(info_storage[0]))) {
        for (size_t i = 0; i < events.size(); i++)
        {
            events[i].check(stoi(info_storage[0]));
        }
        return;
    }
    std::cout << "Invalid or non existing code!" << std::endl;
}

void CMD::report (std::vector<std::string> info_storage, std::vector<Event>& events) {
    std::ofstream event_reports("Event Reports.txt");
    bool in = false;
    Date from(info_storage[0]), to(info_storage[1]);
    if(info_storage.size() == 2) {    
        for (size_t i = 0; i < events.size(); i++)
        {
            if(from <= events[i].get_date() && to >= events[i].get_date()) {
                events[i].event_report(2, event_reports);
                in = true;
            }
        }
    } else if(info_storage.size() == 3) {
        for (size_t i = 0; i < events.size(); i++)
        {
            if(from <= events[i].get_date() && to >= events[i].get_date() && events[i].get_hall().get_id() == stoi(info_storage[2])) {
                events[i].event_report(2, event_reports);
                in = true;
            }
        }
    }
    if(!in) {
        std::cout << "No events to report to in that range!" << std::endl;
    }
    event_reports.close();
}
