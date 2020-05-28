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

int main() {
    std::ifstream r_file;
    
    std::string command_line, action = "", file_name, temp = "";
    size_t k = 0;
    
    std::vector<std::string> info_storage;
    std::vector<Shape *> shapes;

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
        while (command_line[k] != ' ' && command_line[k] != '\0')
        {
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
        
        if(action == "open") {
            CMD::open(shapes, info_storage, r_file, file_name);
        } else if(action == "close") {
            CMD::close(shapes, r_file, file_name);
        } else if(action == "save") {
            CMD::save(shapes, r_file, file_name);
        } else if(action == "saveas") {
            CMD::saveas(shapes, info_storage, r_file);
        } else if (action == "help") {
           CMD::help();
        } else if (action == "/parameters") {
            CMD::parameters();
        } else {
            if(action != "exit") {
                if(r_file.is_open()) {
                    if(action == "print") {
                        CMD::print(shapes);
                    }else if(action == "create") {
                        CMD::create(shapes, info_storage);
                    }else if(action == "erase") {
                        CMD::erase(shapes, info_storage);
                    }else if(action == "translate") {
                        CMD::translate(shapes, info_storage);
                    }else if(action == "within") {
                        CMD::within(shapes, info_storage); 
                    } else {
                        std::cout << "Invalid command entered! Check help for more info!" << std::endl;
                    }
                } else {
                    std::cout << "There isn't an opened file yet to interact whit! Check help for more info!" << std::endl;
                }
            }
        }
    } while (action != "exit");
    std::cout << "Exiting program..." << std::endl;




    return 0;
}