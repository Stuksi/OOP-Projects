#ifndef HALL_H
#define HALL_H

#include <vector>
#include <string>
#include <iostream>

class Hall {
private:
    int rows, cols, id;
    std::vector<std::vector<int>> seats;
    std::vector<std::vector<std::string>> notes;

    bool checkSeat (int _r, int _c);
public:
    Hall (int _id);
    // Hall (int _r, int _c, int _id);
    bool operator== (int _id);
    bool operator== (const Hall& hall);

    void freeseats ();
    void book (int _r, int _c, std::string _note);
    void unbook (int _r, int _c);
    void buy (int _r, int _c, int code);
    void bookings ();
    bool check (int code);
    int report ();

    int findRow (int code);
    int findSeat (int code);

    int getID() {return id};
};

#endif