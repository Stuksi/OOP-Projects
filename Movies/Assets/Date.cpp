#include "Headers\Date.h"

Date::Date() : dd(0), mm(0), yy(0) {}

Date::Date(int _d, int _m, int _y) : dd(_d), mm(_m), yy(_y) {}

Date::Date (std::string date) {
    size_t k = 0;
    dd = findDate(date, k);
    mm = findDate(date, k);
    yy = findDate(date, k);
}


int Date::findDate (std::string date, size_t& k) {
    int dmy = 0;
    while (date[k] != '.' && date[k] != '\0')
    {
        if(date[k] < '0' || date[k] > '9') {
            return 0;
        }
        dmy = dmy * 10 + date[k] - '0';
        k++;
    }
    k++;
    return dmy;
}

bool Date::isValid (std::string date) {
    int d = 0, m = 0, y = 0;
    size_t k = 0;
    
    d = findDate(date, k);
    m = findDate(date, k);
    y = findDate(date, k);
    
    if(y >= 2020) {
        if(m > 0 && m < 13) {
            if(m == 2) {
                return d > 0 && d < 29;
            }
            if(m == 4 || m == 6 || m == 9 || m == 11) {
                return d > 0 && d < 31;
            }
            return d > 0 && d < 32;
        }
    }
    return false;
}

bool Date::operator== (const Date& date) {
    return date.dd == dd && date.mm == mm && date.yy == yy;
}

bool Date::operator>= (const Date& date) {
    return yy >= date.yy || yy == date.yy && mm >= date.mm || yy == date.yy && mm == date.mm && dd >= date.dd;
}

bool Date::operator<= (const Date& date) {
    return yy <= date.yy || yy == date.yy && mm <= date.mm || yy == date.yy && mm == date.mm && dd <= date.dd;
}

std::ostream& operator<< (std::ostream& os, const Date& date) {
    os << date.dd << "." << date.mm << "." << date.yy;
}