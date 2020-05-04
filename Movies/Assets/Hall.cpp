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

Hall::Hall (int _id) : id(_id), rows(5), cols(5) {
    seats.resize(5);
    // notes.resize(5);
    for (size_t i = 0; i < 5; i++) {
        seats[i].resize(5);
        // notes[i].resize(5);
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
    std::cout << std::endl;
    std::cout << "The free seats are whit 0 on your screen, whit 1 are booked seats and whit 2 sold: " << std::endl;
    std::cout << "Rows/Seats : ";
    for (size_t i = 0; i < cols; i++)
    {
        std::cout << "\"" << i+1 << "\" ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        std::cout << "\"" << i+1 << "\"           ";
        for (size_t j = 0; j < cols; j++)
        {
            if(seats[i][j] > 1) {
                std::cout << 2 << "   ";
            } else {
                std::cout << seats[i][j] << "   ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "            ---------------------      <- screen" << std::endl;
    std::cout << std::endl;
}

void Hall::book (int _r, int _c) {
    if(checkSeat(_r, _c)) {
        seats[rows-_r][_c-1] = 1;
        // notes[rows-_r][_c-1] = _note;
        std::cout << "The seat was successfully booked!" << std::endl;
    }
}

void Hall::unbook (int _r, int _c) {
    if(checkSeat(_r, _c)) {
        if(seats[rows-_r][_c-1] == 1) {
            seats[rows-_r][_c-1] = 0;
            // notes[rows-_r][_c-1] = "";
            std::cout << "The seat was successfully unbooked!" << std::endl;
        } else {
            std::cout << "The seat is either still not booked or its bought!" << std::endl;
        }
    }
}

void Hall::buy (int _r, int _c, int code) {
    if(checkSeat(_r, _c)) {
        if(seats[rows-_r][_c-1] == 0) {
            seats[rows-_r][_c-1] = code;
            std::cout << "The seat was successfully bought! The code for the seat is: " << code << std::endl;
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
            if (seats[i][j] == 1) {
                freeseats();
                return;
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
            if(seats[i][j] > 1) {
                counter++;
            }
        }
    }
    return counter;
}