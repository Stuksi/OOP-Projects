#ifndef COMMHNDL_H
#define COMMHNDL_H

#include "Movie.h"

#include <vector>
#include <string>
#include <fstream>

class CommHndl {
private:
    static bool isValidInteger (std::string number);
    static bool exists (std::string fileName);
    static bool empty_File (std::string fileName);
public:
    static void open (std::ifstream& file, std::vector<std::string> infoStorage, std::vector<Movie> movies, std::string fileName); 
    static void close (std::ifstream& file, std::vector<Movie> movies, std::string fileName); 
    static void save (std::ifstream& file, std::vector<Movie> movies, std::string fileName); 
    static void saveas (std::ifstream& file, std::vector<std::string> infoStorage, std::vector<Movie> movies); 
    static void help (); 
    
    static void addevent (std::vector<std::string> infoStorage, std::vector<Movie>& movies); 
    static void freeseats (std::vector<std::string> infoStorage, std::vector<Movie>& movies); 
    static void book (std::vector<std::string> infoStorage, std::vector<Movie>& movies); 
    static void unbook (std::vector<std::string> infoStorage, std::vector<Movie>& movies); 
    static void buy (std::vector<std::string> infoStorage, std::vector<Movie>& movies, std::vector<int>& codes); 
    static void bookings (std::vector<std::string> infoStorage, std::vector<Movie>& movies); 
    static void check (std::vector<std::string> infoStorage, std::vector<Movie>& movies, std::vector<int>& codes); 
    static void report (std::vector<std::string> infoStorage, std::vector<Movie>& movies); 
};

#endif