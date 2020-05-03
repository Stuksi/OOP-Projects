#include "Headers\CommHndl.h"
#include "Headers\Date.h"
#include "Headers\Hall.h"

#include <iostream>
#include <algorithm>
#include <ctime>

bool CommHndl::exists(std::string fileName) {
    std::fstream file(fileName);
    return file.good();
}

bool CommHndl::empty_File(std::string fileName) {
    std::fstream file(fileName);
    return file.peek() == std::ifstream::traits_type::eof();
}

bool CommHndl::isValidInteger (std::string number) {
    for (size_t i = 0; i < number.length(); i++)
    {
        if(number[i] < '0' || number[i] > '9') {
            return false;
        }
    }
    return true;
}

void CommHndl::open (std::ifstream& r_File, std::vector<std::string> infoStorage, std::vector<Movie> movies, std::string fileName) {
    if(exists(infoStorage[0])) {
        fileName = infoStorage[0];
        r_File.open(fileName);
        if(!empty_File(fileName)){
            r_File >> movies;
        }
        std::cout << fileName << " opened successfully!" << std::endl;
    } else {
        std::cout << infoStorage[0] << " does not exist!" << std::endl;
    }
}

void CommHndl::close (std::ifstream& r_File, std::vector<Movie> movies, std::string fileName) {
    if(r_File.is_open()) {
        movies.clear();
        r_File.close();
        std::cout << fileName << " closed successfully!" << std::endl;
        fileName = "";
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CommHndl::save (std::ifstream& r_File, std::vector<Movie> movies, std::string fileName) {
    if(r_File.is_open()) {
        std::ofstream w_File(fileName);
        w_File << movies;
        w_File.close();
        std::cout << "Information saved successfully to " << fileName << "!" << std::endl;
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CommHndl::saveas (std::ifstream& r_File, std::vector<std::string> infoStorage, std::vector<Movie> movies) {
    if(r_File.is_open()) {
        if(!exists(infoStorage[0])){
            std::ofstream w_File(infoStorage[0]);
            w_File << movies;
            w_File.close();
            std::cout << "Information saved successfully to " << infoStorage[0] << "!" << std::endl;
        }else {
            std::cout << "The file name already exists!" << std::endl;
        }
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CommHndl::help () {
    
}

void CommHndl::addevent (std::vector<std::string> infoStorage, std::vector<Movie>& movies) {
    if(Date::isValid(infoStorage[0]) && isValidInteger(infoStorage[1])) {
        Date date(infoStorage[0]);
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(movies[i].getDate() == date && movies[i].getHall() == stoi(infoStorage[1])) {
                std::cout << "There's already another movie at " << date << " in hall: " << infoStorage[1] << std::endl;
                return;
            }
        }
        Hall newHall (stoi(infoStorage[1]));
        Movie newMovie (date, newHall, infoStorage[2]);
        movies.push_back(newMovie);
    } else {
        std::cout << "Invalid use of command or parameters!" << std::endl;
    }
}

void CommHndl::freeseats (std::vector<std::string> infoStorage, std::vector<Movie>& movies) {
    if(Date::isValid(infoStorage[0])) {
        Date date(infoStorage[0]);
        bool in = false;
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(movies[i].getDate() == date && movies[i].getName() == infoStorage[1]) {
                in = true;
                movies[i].freeseats();
            }
        }
        if (!in) {
            std::cout << "No movies whit that name on that date!" << std::endl;
        }
    } else {
        std::cout << "Invalid use of command or parameters!" << std::endl;
    }
}

void CommHndl::book (std::vector<std::string> infoStorage, std::vector<Movie>& movies) {
    if(Date::isValid(infoStorage[2]) && isValidInteger(infoStorage[0]) && isValidInteger(infoStorage[1])) {
        Date date(infoStorage[2]);
        bool in = false;
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(movies[i].getDate() == date && movies[i].getName() == infoStorage[3]) {
                in = true;
                movies[i].book(stoi(infoStorage[0]), stoi(infoStorage[1]), infoStorage[4]);
                return;
            }
        }
        if (!in) {
            std::cout << "No movies whit that name on that date!" << std::endl;
        }
    } else {
        std::cout << "Invalid use of command or parameters!" << std::endl;
    }
}

void CommHndl::unbook (std::vector<std::string> infoStorage, std::vector<Movie>& movies) {
    if(Date::isValid(infoStorage[2]) && isValidInteger(infoStorage[0]) && isValidInteger(infoStorage[1])) {
        Date date(infoStorage[2]);
        bool in = false;
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(movies[i].getDate() == date && movies[i].getName() == infoStorage[3]) {
                in = true;
                movies[i].unbook(stoi(infoStorage[0]), stoi(infoStorage[1]));
                return;
            }
        }
        if (!in) {
            std::cout << "No movies whit that name on that date!" << std::endl;
        }
    } else {
        std::cout << "Invalid use of command or parameters!" << std::endl;
    }
}

void CommHndl::buy (std::vector<std::string> infoStorage, std::vector<Movie>& movies, std::vector<int>& codes) {
     if(Date::isValid(infoStorage[2]) && isValidInteger(infoStorage[0]) && isValidInteger(infoStorage[1])) {
        Date date(infoStorage[2]);
        bool in = false;
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(movies[i].getDate() == date && movies[i].getName() == infoStorage[3]) {
                in = true;
                int code;
                srand(time(NULL));
                do
                {
                    code = rand() % 10000 + 2;
                } while (std::binary_search(codes.begin(), codes.end(), code));
                codes.push_back(code);
                movies[i].buy(stoi(infoStorage[0]), stoi(infoStorage[1]), code);
                return;
            }
        }
        if (!in) {
            std::cout << "No movies whit that name on that date!" << std::endl;
        }
    } else {
        std::cout << "Invalid use of command or parameters!" << std::endl;
    }
}

void CommHndl::bookings (std::vector<std::string> infoStorage, std::vector<Movie>& movies) {
     if(infoStorage.size() == 2 && Date::isValid(infoStorage[0])) {
        Date date(infoStorage[0]);
        bool in = false;
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(infoStorage[1] == movies[i].getName() && date == movies[i].getDate()) {
                in = true;
                movies[i].bookings();
            }
        }
        if (!in) {
            std::cout << "No movies whit that name on that date!" << std::endl;
        }         
    } else if(infoStorage.size() == 1 && Date::isValid(infoStorage[0])) {
        Date date(infoStorage[0]);
        bool in = false;
        for (size_t i = 0; i < movies.size(); i++)
        {
            if(date == movies[i].getDate()) {
                in = true;
                movies[i].bookings();
            }
        }
        if (!in) {
            std::cout << "No movies on that date!" << std::endl;
        }
    } else if(infoStorage.size() == 0) {
        for (size_t i = 0; i < movies.size(); i++)
        {
            movies[i].bookings();
        }
        if (movies.size() == 0) {
            std::cout << "No movies to display information for!" << std::endl;
        }
    } 
}

void CommHndl::check (std::vector<std::string> infoStorage, std::vector<Movie>& movies, std::vector<int>& codes) {
    if(isValidInteger(infoStorage[0]) && std::binary_search(codes.begin(), codes.end(), stoi(infoStorage[0]))) {
        for (size_t i = 0; i < movies.size(); i++)
        {
            movies[i].check(stoi(infoStorage[0]));
        }
    }
}

void CommHndl::report (std::vector<std::string> infoStorage, std::vector<Movie>& movies) {
    if(Date::isValid(infoStorage[0]) && Date::isValid(infoStorage[1])) {
        bool in = false;
        Date from(infoStorage[0]);
        Date to(infoStorage[0]);
        if(infoStorage.size() == 2) {    
            for (size_t i = 0; i < movies.size(); i++)
            {
                if(from <= movies[i].getDate() && to >= movies[i].getDate()) {
                    movies[i].report();
                    in = true;
                }
            }
            if(!in) {
                std::cout << "No movies to report to in that range!" << std::endl;
            }
        } else if(infoStorage.size() == 3 && isValidInteger(infoStorage[2])) {
            for (size_t i = 0; i < movies.size(); i++)
            {
                if(from <= movies[i].getDate() && to >= movies[i].getDate() && movies[i].getHall() == stoi(infoStorage[2])) {
                    movies[i].report();
                    in = true;
                }
            }
            if(!in) {
                std::cout << "No movies to report to in that range!" << std::endl;
            }
        } else {
            std::cout << "Wrong use of command!" << std::endl;
        }
    }
}
