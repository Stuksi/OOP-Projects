#ifndef EVENT_H
#define EVENT_H

#include "Date.h"
#include "Hall.h"
#include <vector>

class Event {
private:
    Date movie_date;
    Hall movie_hall;
    std::string movie_name;
public:
    Event(Date, Hall, std::string);

    void print_hall();
    void update_hall_seat(int, int, int);
    void event_report(int, std::ostream& os);
    void check(int);

    Date get_date();
    std::string get_name();
    Hall get_hall();
};

std::ostream& operator<< (std::ostream&, std::vector<Event>);
std::istream& operator>> (std::istream&, std::vector<Event>&);

#endif