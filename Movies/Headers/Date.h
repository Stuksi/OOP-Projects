#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date {
private:
    int year, month, day;

    bool valid(int, int, int);
public:
    Date();
    Date(const Date&);
    Date(int, int, int);
    Date(const std::string);

    Date operator= (const Date&);
    bool operator== (const Date&);
    bool operator!= (const Date&);
    bool operator>= (const Date&);
    bool operator<= (const Date&);
    bool operator< (const Date&);
    bool operator> (const Date&);

    friend std::ostream& operator<< (std::ostream&, const Date&);
};

#endif