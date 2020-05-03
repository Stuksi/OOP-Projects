#include "Headers\Movie.h"

#include <algorithm>

Movie::Movie (Date _date, Hall _hall, std::string _name) : date(_date), hall(_hall), name(_name) {}

void Movie::freeseats () {
    hall.freeseats();
}

void Movie::book (int _r, int _c, std::string _note) {
    hall.book(_r, _c, _note);
}

void Movie::unbook (int _r, int _c) {
    hall.unbook (_r, _c);
}

void Movie::buy (int _r, int _c, int code) {
    hall.buy (_r, _c, code);
}

void Movie::bookings () {
    hall.bookings();
}

void Movie::check (int code) {
    if(hall.check(code)) {
        std::cout << name << " : Row: " << hall.findRow(code) << " - Seat: " << hall.findSeat(code) << " Date: " << date << std::endl;
    }
}

void Movie::report () {
    std::cout << "On " << date << " for the movie " << name << ", there is a total of " << hall.report() << " tickets sold!" << std::endl; 
}

Date Movie::getDate () {
    return date;
}

Hall Movie::getHall () {
    return hall;
}

int Movie::getHallID () {
    return hall.getID();
}

std::string Movie::getName () {
    return name;
}

std::ostream& operator<< (std::ostream& os, std::vector<Movie>& movies) {
    std::sort(movies.begin(), movies.end(), [](Movie& a, Movie& b)->bool{return a.getDate() <= b.getDate();});
    size_t k = 0;
    for (size_t i = k; i < movies.size()-1; i++)
    {
        os << "Date: \"" << movies[i].getDate() << "\"\n";
        for (size_t j = k+1; j < movies.size(); j++)
        {
            if(movies[i].getDate() == movies[j].getDate()) {
                k++;
                os << "    Movie: \"" << movies[i].getName() << "\" - Hall: \"" << movies[i].getHallID() << "\"|\n";
            }
        }
          
    }
    
}

std::istream& operator>> (std::istream& is, std::vector<Movie>& movies) {
    std::string fileTxT = "", temp, date;
    std::vector<std::string> values;
    size_t i = 1;

    while (is >> temp)
    {
        fileTxT += temp;
    }
    
    temp = "";

    while (fileTxT[i] != '\0')
    {
        while (fileTxT[i] != '"')
        {
            i++;
        }
        i++;
        while (fileTxT[i] != '"')
        {
            date += fileTxT[i];
            i++;
        }
        Date newDate(date);
        while (fileTxT[i] != '/')
        {
            while (fileTxT[i] != '|' || fileTxT[i] != '/')
            {
                if(fileTxT[i] == '"') {
                    while (fileTxT[i] != '"')
                    {
                        temp += fileTxT[i];
                        i++;
                    } 
                    values.push_back(temp);
                    temp = "";
                }
                i++;
            }
            if(fileTxT[i] != '/') {    
                Hall hall(stoi(values[1]));
                Movie newMovie(newDate, hall, values[0]);
                values.clear();
                temp = "";
            }
        }
        i++;   
    }
    
}