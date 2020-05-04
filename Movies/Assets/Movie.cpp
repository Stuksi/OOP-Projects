#include "Headers\Movie.h"

#include <algorithm>

Movie::Movie (Date _date, Hall _hall, std::string _name) : date(_date), hall(_hall), name(_name) {}

void Movie::freeseats () {
    hall.freeseats();
}

void Movie::book (int _r, int _c) {
    hall.book(_r, _c);
}

void Movie::unbook (int _r, int _c) {
    hall.unbook (_r, _c);
}

void Movie::buy (int _r, int _c, int code) {
    hall.buy (_r, _c, code);
}

void Movie::bookings () {
    hall.bookings ();
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

int Movie::getHall () {
    return hall.getID();
}

std::string Movie::getName () {
    return name;
}

std::ostream& operator<< (std::ostream& os, std::vector<Movie>& movies) {
    int minIndex;
    for (size_t i = 0; i < movies.size()-1; i++)
    {
        minIndex = i;
        for (size_t j = i+1; j < movies.size(); j++) {
            if(movies[minIndex].getDate() < movies[j].getDate()) {
                minIndex = j;
            }
        }
        Movie swap = movies[minIndex];
        movies[minIndex] = movies[i];
        movies[i] = swap;
    }
    
    size_t j = 0, k = 0;
    for (size_t i = 0; i < movies.size(); i+=k)
    {
        k = 0;
        os << "Date: \"" << movies[i].getDate() << "\"\n";
        while (movies[i].getDate() == movies[j].getDate())
        {
            if(movies[i].getDate() != movies[j+1].getDate()) {
                os << "    Movie: \"" << movies[j].getName() << "\" - Hall: \"" << movies[j].getHall() << "\"/\n";
            } else {
                os << "    Movie: \"" << movies[j].getName() << "\" - Hall: \"" << movies[j].getHall() << "\"|\n";
            }
            j++;
            k++;
        } 
    }
    return os;
}

std::istream& operator>> (std::istream& is, std::vector<Movie>& movies) {
    std::string fileTxT = "", temp, date;
    std::vector<std::string> values;
    size_t i = 0;

    while (is >> temp)
    {
        fileTxT += temp;
    }
    
    temp = "";

    while (i < fileTxT.length())
    {
        date = "";
        while (fileTxT[i] != '"' && i < fileTxT.length())
        {
            i++;
        }
        i++;
        while (fileTxT[i] != '"' && i < fileTxT.length())
        {
            date += fileTxT[i];
            i++;
        }
        Date newDate(date);
        i++; 
        while (fileTxT[i] != '/' && i < fileTxT.length())
        {
            while (fileTxT[i] != '|' && fileTxT[i] != '/')
            {
                if(fileTxT[i] == '"') {
                    i++;
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
            Hall newHall (stoi(values[1]));
            Movie newMovie (newDate, newHall, values[0]);
            movies.push_back(newMovie);
            values.clear();
            if(fileTxT[i] == '/') {
                break;
            }
            i++;
        }
    }
    return is;
}