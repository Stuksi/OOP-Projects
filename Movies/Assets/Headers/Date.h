#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int dd,mm,yy;

    static int findDate (std::string date, size_t& k);
public:
    Date ();
    Date (int _d, int _m, int _y);
    Date (std::string date);
    bool operator== (const Date& date);
    bool operator!= (const Date& date);
    bool operator>= (const Date& date);
    bool operator<= (const Date& date);
    bool operator< (const Date& date);
    bool operator> (const Date& date);

    static bool isValid (std::string date);

    friend std::ostream& operator<< (std::ostream& os, const Date& date);
};


#endif