#include "..\Headers\Date.h"

#include <stdexcept>
#include <iostream>

Date::Date() : year(0), month(0), day(0) {}

Date::Date(const Date& date) : year(date.year), month(date.month), day(date.day) {}

Date::Date(int yy, int mm, int dd) {
    try
    {
        valid(yy, mm, dd);
    }
    catch(const std::invalid_argument& error)
    {
        std::cerr << error.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    year = yy;
    month = mm;
    day = dd;
}

Date::Date(const std::string date) {
    int yy = (date[0]-'0') * 1000 + (date[1]-'0') * 100 + (date[2]-'0') * 10 + date[3]-'0';
    int mm = (date[5]-'0') * 10 + date[6]-'0';
    int dd = (date[8]-'0') * 10 + date[9]-'0';
    try
    {
        valid(yy, mm, dd);
    }
    catch(const std::invalid_argument& error)
    {
        std::cerr << error.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    year = yy;
    month = mm;
    day = dd;
}

bool Date::valid(int yy, int mm, int dd) {
    if(yy >= 2020 && mm < 13 && mm > 0 && dd > 0) {
        if(mm == 2) {
            return dd < 29;
        } else if(mm == 4 || mm == 6 || mm == 9 || mm == 11) {
            return dd < 31;
        } else {
            return dd < 32; 
        }
    }
    throw std::invalid_argument("Invalid date initialization! Date must be a valid, future date in the ISO 8601 format.");
    return false;
}

Date Date::operator=(const Date& date) {
    if(this != &date) {
        year = date.year;
        month = date.month;
        day = date.day;
    }
    return *this;
}

bool Date::operator==(const Date& date) {
    return year == date.year && month == date.month && day == date.day;
}

bool Date::operator!=(const Date& date) {
    return year != date.year || month != date.month || day != date.day;
}

bool Date::operator>=(const Date& date) {
    return year > date.year || year == date.year && month > date.month || year == date.year && month == date.month && day >= date.day;
}

bool Date::operator<=(const Date& date) {
    return year < date.year || year == date.year && month < date.month || year == date.year && month == date.month && day <= date.day;
}

bool Date::operator<(const Date& date) {
    return year < date.year || year == date.year && month < date.month || year == date.year && month == date.month && day < date.day;
}

bool Date::operator>(const Date& date) {
    return year > date.year || year == date.year && month > date.month || year == date.year && month == date.month && day > date.day;
}

std::ostream& operator<< (std::ostream& os, const Date& date) {
    os << date.year << "-";
    if(date.month < 10) {
        os << "0" << date.month;
    } else {
        os << date.month;
    }
    os << "-";
    if(date.day < 10) {
        os << "0" << date.day;
    } else {
        os << date.day;
    }
    return os; 
}