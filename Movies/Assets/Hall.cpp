#include "Headers\Hall.h"

#include <ctime>
#include <algorithm>

int Hall::findRow (int code) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if(seats[i][j] == code) {
                return i+1;
            }
        }
    }
    return 0;
}

int Hall::findSeat (int code) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if(seats[i][j] == code) {
                return j+1;
            }
        }
    }
    return 0;
}

bool Hall::checkSeat (int _r, int _c) {
    if(_r > 0 && _r <= rows && _c > 0 && _c <= cols) {
        return true;
    }
    std::cout << "Invalid seat!" << std::endl;
    return false;
}

Hall::Hall (int _id) : id(_id) {
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            seats[i][j] = 0;
            notes[i][j] = "";
        }
    }
}

// Hall::Hall (int _r, int _c, int _id) : rows(_r), cols(_c), id(_id) {
//     for (size_t i = 0; i < _r; i++)
//     {
//         for (size_t j = 0; j < _c; j++)
//         {
//             seats[i][j] = 0;
//             notes[i][j] = "";
//         }
//     }
// }

bool Hall::operator== (int _id) {
    return id == _id;
}

bool Hall::operator== (const Hall& hall) {
    return id == hall.id;
}

void Hall::freeseats () {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if(seats[i][j] == 0) {
                std::cout << "Row: " << i+1 << " - Seat: " << j+1 << std:: endl;
            }
        }
    }
}

void Hall::book (int _r, int _c, std::string _note) {
    if(checkSeat(_r, _c)) {
        seats[rows-_r][_c-1] = -1;
        notes[rows-_r][_c-1] = _note;
    }
}

void Hall::unbook (int _r, int _c) {
    if(checkSeat(_r, _c)) {
        if(seats[rows-_r][_c-1] == -1) {
            seats[rows-_r][_c-1] = 0;
            notes[rows-_r][_c-1] = "";
        } else {
            std::cout << "The seat is either still not booked or its bought!" << std::endl;
        }
    }
}

void Hall::buy (int _r, int _c, int code) {
    if(checkSeat(_r, _c)) {
        if(seats[rows-_r][_c-1] == 0) {
            seats[rows-_r][_c-1] = code;
        } else {
            std::cout << "The seat is booked or already bought!" << std::endl;
        }
    }
}

void Hall::bookings () {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if(seats[i][j] == -1) {
                std::cout << "Row: " << i+1 << " - Seat: " << j+1 << std::endl;
            }
        }
    }
}

bool Hall::check (int code) {
    return findRow(code) != 0;
}

int Hall::report () {
    size_t counter = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if(seats[i][j] > 0) {
                counter++;
            }
        }
    }
    return counter;
}