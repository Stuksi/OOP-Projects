#include "..\Headers\Hall.h"

#include <ctime>

Hall::Hall() {
    for (size_t i = 0; i < hall_rows; i++)
    {
        for (size_t j = 0; j < hall_cols; j++)
        {
            hall_seats[i][j] = 0;   
        }
    }
}

Hall::Hall(int _id) : id(_id) {
    for (size_t i = 0; i < hall_rows; i++)
    {
        for (size_t j = 0; j < hall_cols; j++)
        {
            hall_seats[i][j] = 0;   
        }
    }
}

void Hall::print_hall() {
    std::cout << std::endl;
    std::cout << "The free seats are whit 0 on your screen, whit 1 are booked seats and whit 2 sold: " << std::endl;
    std::cout << "Rows/Seats : ";
    for (size_t i = 0; i < hall_rows; i++)
    {
        std::cout << "\"" << i+1 << "\" ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < hall_rows; i++)
    {
        std::cout << "\"" << hall_rows-i << "\"           ";
        for (size_t j = 0; j < hall_cols; j++)
        {
            if(hall_seats[i][j] > 1) {
                std::cout << 2 << "   ";
            } else {
                std::cout << hall_seats[i][j] << "   ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "            ---------------------      <- screen" << std::endl;
    std::cout << std::endl;
}

bool Hall::set_seat(int type, int row, int col) {
    try
    {
        if(row < 1 || row > hall_rows || col < 0 || col >= hall_cols) {
            throw "Invalid row and col values!";
        }
    }
    catch(const char* error)
    {
        std::cerr << error << '\n';
        std::exit(EXIT_FAILURE);
    }
    
    if((type == 0 && hall_seats[hall_rows-row][col] != 0)
    || (type > 0 && hall_seats[hall_rows-row][col] == 0)) {
        if(type == 0) {
            std::cout << "Unbooking seat at: Row: " << row << ", Col: " << col+1;
        } else if(type == 1) {
            std::cout << "Booking seat at: Row: " << row << ", Col: " << col+1;
        } else if(type > 1) {
            std::cout << "Ticket Code: " << type << "! Buying seat at: Row: " << row << ", Col: " << col+1;
        }
        hall_seats[hall_rows-row][col] = type;
        return true;
    }
    return false;
}

bool Hall::find_seat(int code) {
    for (size_t i = 0; i < hall_rows; i++)
    {
        for (size_t j = 0; j < hall_cols; j++)
        {
            if(hall_seats[i][j] == code) {
                std::cout << "Row: " << hall_rows-i << ", Col: " << j+1;
                return true;
            }
        }
    }
    return false;
}

void Hall::report(int report_type, std::ostream& event_reports) {
    if(report_type == 0) {
        event_reports << "Free seats:\n";
    } else if(report_type == 1) {
        event_reports << "Booked seats:\n";
    } else if(report_type == 2) {
        event_reports << "Bought seats:\n";
    }
    for (size_t i = 0; i < hall_rows; i++)
    {
        for (size_t j = 0; j < hall_cols; j++)
        {
            if(report_type == hall_seats[i][j] || (hall_seats[i][j] >= 2 && report_type == 2)) {
                event_reports << "Row: " << hall_rows-i << " Col: " << j+1 << "\n"; 
            }
        }
    }
}

int Hall::get_id() {
    return id;
}