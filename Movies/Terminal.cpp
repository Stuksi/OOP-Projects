#include "Assets\Headers\CommHndl.h"

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

    std::string commandLine, action = "", fileName, temp = "";
    std::ifstream r_File;
    std::vector<std::string> infoStorage;
    std::vector<Movie> movies;
    std::vector<int> codes;
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
            CommHndl::open(r_File, infoStorage, movies, fileName);
        } else if(action == "close") {
            CommHndl::close(r_File, movies, fileName);
        } else if(action == "save") {
            CommHndl::save(r_File, movies, fileName);
        } else if(action == "saveas") {
            CommHndl::saveas(r_File, infoStorage, movies);
        } else if(action == "help") {
            CommHndl::help();          
        } else {
            if(action == "addevent") {
                CommHndl::addevent(infoStorage, movies);
            } else if(action == "freeseats") {
                CommHndl::freeseats(infoStorage, movies);
            } else if(action == "book") {
                CommHndl::book(infoStorage, movies);
            } else if(action == "unbook") {
                CommHndl::unbook(infoStorage, movies);
            } else if(action == "buy") {
                CommHndl::buy(infoStorage, movies, codes);
            } else if(action == "bookings") {
                CommHndl::bookings(infoStorage, movies);
            } else if(action == "check") {
                CommHndl::check(infoStorage, movies, codes);
            } else if(action == "report") {
                CommHndl::report(infoStorage, movies);
            } else {

            }   
        }
    } while(action != "exit");
    std::cout << "Exiting program..." << std::endl;

    return 0;
}