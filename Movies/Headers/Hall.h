#ifndef HALL_H
#define HALL_H

#include <iostream>

const int hall_rows = 5;
const int hall_cols = 5;

class Hall {
private:
    int hall_seats[hall_rows][hall_cols], id;
public:
    Hall();
    Hall(int);

    void print_hall();
    bool set_seat(int, int, int);
    void report(int, std::ostream&);
    bool find_seat(int);
    int get_id();
};

#endif