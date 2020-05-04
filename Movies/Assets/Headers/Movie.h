#ifndef MOVIE_H
#define MOVIE_H

#include "Date.h"
#include "Hall.h"

class Movie {
private:
    Date date;
    Hall hall;
    std::string name;
public:
    Movie (Date _date, Hall _hall, std::string _name);

    void freeseats ();
    void book (int _r, int _c);
    void unbook (int _r, int _c);
    void buy (int _r, int _c, int code);
    void bookings ();
    void check (int code);
    void report ();

    Date getDate ();
    int getHall ();
    std::string getName ();
};

std::ostream& operator<< (std::ostream& os, std::vector<Movie>& movies); 
std::istream& operator>> (std::istream& is, std::vector<Movie>& movies); 

#endif