#include "..\Headers\Event.h"

#include <functional>
#include <fstream>

Event::Event(Date event_date, Hall event_hall, std::string event_name) : movie_date(event_date), movie_hall(event_hall), movie_name(event_name) {}

void Event::print_hall() {
    movie_hall.print_hall();
}

void Event::update_hall_seat(int purchase_type, int row, int col) {
    if(movie_hall.set_seat(purchase_type, row, col-1)) {
        std::cout << " for Movie: " << movie_name << " on Date: " << movie_date << " in Hall: " << movie_hall.get_id() << "!\n"; 
    } else {
        if(purchase_type == 0) {
            std::cout << "Seat is already free!" << std::endl;
        } else if(purchase_type > 0) {
            std::cout << "Seat is already taken!" << std::endl;
        }
    }
}

void Event::event_report(int report_type, std::ostream& os) {
    os << "Event Reports:\n";
    os << "-------------------------------------------------\n\n"; 
    os << "Date: " << movie_date << " Movie: " << movie_name << " Hall: " << movie_hall.get_id() << "!\n"; 
    movie_hall.report(report_type, os);
    os << "\n";
}

void Event::check(int code) {
    if(movie_hall.find_seat(code)) {
        std::cout << "! For ticket whit code: " << code << " - Movie: " << movie_name << " Date: " << movie_date << "!\n";
    }
}

std::ostream& operator<< (std::ostream& os, std::vector<Event> events) {  
    int minIndex;
    for (size_t i = 0; i < events.size()-1; i++)
    {
        minIndex = i;
        for (size_t j = i+1; j < events.size(); j++)
        {
            if(events[minIndex].get_date() < events[j].get_date()) {
                minIndex = j;
            }
        }
        Event swap = events[minIndex];
        events[minIndex] = events[i];
        events[i] = swap;
    }
    
    for (size_t i = 0; i < events.size(); i++)
    {
        os << "Date: \"" << events[i].get_date() << "\"\n";
        while (events[i].get_date() == events[i+1].get_date())
        {
            os << "    Movie: \"" << events[i].get_name() << "\" - Hall: \"" << events[i].get_hall().get_id() << "\"\n";
            i++;
        }   
        os << "    Movie: \"" << events[i].get_name() << "\" - Hall: \"" << events[i].get_hall().get_id() << "\"/\n";
    }
    return os;
}

std::istream& operator>> (std::istream& is, std::vector<Event>& events) {
    std::string file_info = "", temp;

    while (std::getline(is, temp))
    {
        file_info += temp;
    }
    
    std::function<std::string(size_t&)> string_slice = [file_info](size_t& i)->std::string {
        std::string result = "";
        while (file_info[i] != '"')
        {
            result+=file_info[i];
            i++;
        }
        return result;
    };

    std::function<int(size_t&)> string_to_int = [file_info](size_t& i)->int {
        std::string result = "";
        while (file_info[i] != '"')
        {
            result+=file_info[i];
            i++;
        }
        return stoi(result);
    };

    std::string movie_date, movie_name = "";
    int hall_id;

    for (size_t i = 0; i < file_info.length(); i++)
    {
        while (file_info[i] != '"')
        {
            i++;
        }
        i++;
        movie_date = string_slice(i);
        Date date(movie_date);
        i++;
        while (file_info[i] != '/')
        {
            if(file_info[i] == '"') {
                i++;
                if(movie_name == "") {
                    movie_name = string_slice(i);
                } else {
                    hall_id = string_to_int(i);
                    Hall hall(hall_id);
                    Event event(date, hall, movie_name);
                    events.push_back(event);
                    movie_name = "";
                }
            }
            i++;
        }
    }
    return is;
}

Date Event::get_date() {
    return movie_date;
}

std::string Event::get_name() {
    return movie_name;
}

Hall Event::get_hall() {
    return movie_hall;
}
