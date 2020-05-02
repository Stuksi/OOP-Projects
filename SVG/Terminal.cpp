#include "Assets\Headers\Figure.h"
#include "Assets\Headers\CommandHandle.h"

#include <fstream>

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

    std::ifstream r_File;
    std::string commandLine, action = "", fileName, temp = "";
    std::vector<std::string> infoStorage;
    std::vector<Figure *> figures;
    size_t k = 0;

    do
    {
        action = "";
        temp = "";
        infoStorage.clear();
        k = 0;

        std::getline(std::cin, commandLine);

        skipEmptySpaces(commandLine, k);
        while (commandLine[k] != ' ' && commandLine[k] != '\0')
        {
            action += commandLine[k];
            k++;
        }
        skipEmptySpaces(commandLine, k);
        while (commandLine[k] != ' ' && commandLine[k] != '\0')
        {
            if(commandLine[k] != ' ' && commandLine[k] != '\0') {
                temp += commandLine[k];
                k++;
            }
            if(commandLine[k] == ' ' || commandLine[k] == '\0') {
                infoStorage.push_back(temp);
                temp = "";
                skipEmptySpaces(commandLine, k);
            }
        }
        
        if(action == "open") {
            CommandHandle::open(figures, infoStorage, r_File, fileName);
        } else if(action == "close") {
            CommandHandle::close(figures, r_File, fileName);
        } else if(action == "save") {
            CommandHandle::save(figures, r_File, fileName);
        } else if(action == "saveas") {
            CommandHandle::saveas(figures, infoStorage, r_File);
        } else if (action == "help") {
           CommandHandle::help();
        } else if (action == "/parameters") {
            CommandHandle::parameters();
        } else {
            if(action != "exit") {
                if(r_File.is_open()) {
                    if(action == "print") {
                        CommandHandle::print(figures);
                    }else if(action == "create") {
                        CommandHandle::create(figures, infoStorage);
                    }else if(action == "erase") {
                        CommandHandle::erase(figures, infoStorage);
                    }else if(action == "translate") {
                        CommandHandle::translate(figures, infoStorage);
                    }else if(action == "within") {
                        CommandHandle::within(figures, infoStorage); 
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