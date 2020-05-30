#include "Headers\Command_Prompt.h"

void skipEmptySpaces(std::string& string, size_t &k) {
    while (string[k] == ' ')
    {
        if(k >= string.length()){
            return;
        }
        k++;
    }
}

int main () {
    std::ifstream r_file;
    
    std::string command_line, action = "", file_name, temp = "";
    size_t k = 0;
    
    std::vector<std::string> info_storage;
    std::vector<int> codes;
    std::vector<Event> events;

    do
    {
        action = "";
        temp = "";
        info_storage.clear();
        k = 0;

        std::getline(std::cin, command_line);

        skipEmptySpaces(command_line, k);
        while (command_line[k] != ' ' && command_line[k] != '\0')
        {
            action += command_line[k];
            k++;
        }
        skipEmptySpaces(command_line, k);
        if(action != "open") {
            while (command_line[k] != ' ' && command_line[k] != '\0')
            {
                if(command_line[k] == '"') {
                    k++;
                    while (command_line[k] != '"')
                    {
                        temp += command_line[k];
                        k++;
                    }
                    k++;
                }
                if(command_line[k] != ' ' && command_line[k] != '\0') {
                    temp += command_line[k];
                    k++;
                }
                if(command_line[k] == ' ' || command_line[k] == '\0') {
                    info_storage.push_back(temp);
                    temp = "";
                    skipEmptySpaces(command_line, k);
                }
            }
        } else {
            while (command_line[k] != '\0')
            {
                file_name += command_line[k];
                k++;
            }
        }

        if(action == "open") {
            CMD::open(r_file, events, file_name);
        } else if(action == "close") {
            CMD::close(r_file, events, file_name);
        } else if(action == "save") {
            CMD::save(r_file, events, file_name);
        } else if(action == "saveas") {
            CMD::saveas(r_file, info_storage, events);
        } else if(action == "help") {
            CMD::help();          
        } else {
            if(action == "addevent") {
                CMD::add_event(info_storage, events);
            } else if(action == "freeseats") {
                CMD::free_seats(info_storage, events);
            } else if(action == "book") {
                CMD::access_seats(info_storage, events, codes, 1);
            } else if(action == "unbook") {
                CMD::access_seats(info_storage, events, codes, 0);
            } else if(action == "buy") {
                CMD::access_seats(info_storage, events, codes, 2);
            } else if(action == "bookings") {
                CMD::bookings(info_storage, events);
            } else if(action == "check") {
                CMD::check(info_storage, events, codes);
            } else if(action == "report") {
                CMD::report(info_storage, events);
            } else {

            }   
        }
    } while(action != "exit");
    std::cout << "Exiting program..." << std::endl;

    return 0;
}