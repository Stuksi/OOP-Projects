#ifndef EVENT_H
#define EVENT_H

#include "Date.h"
#include "Hall.h"
#include <vector>

/**
 * Клас Event.
 * Класът Event представлява обект съдържащ дата на прожекция на даден филм,
 * името на филма и залата в която ще се прожектира.
 */

class Event {
private:
    Date movie_date; /**< Дата на прожекцията. */
    Hall movie_hall; /**< Зала на прожекцията. */
    std::string movie_name; /**< Име на филма. */
public:
    Event(Date, Hall, std::string); /**< Конструктора инициализира обекта по подадени
                                         дата, зала и име на прожекция. */

    void print_hall(); /**< Извежда на конзолата залата и показва информация за местата. */
    void update_hall_seat(int, int, int); /**< Променя състоянието на дадено място в залата. */
    void event_report(int, std::ostream& os); /**< Извежда във файл информация за прожекцията(закупени места, свободни места, запазени места). */
    void check(int); /**< Проверява по даден код на билет дали съответства място в залата. */

    /** \return Дава датата на прожекцията.  */
    Date get_date(); 
    /** \return Дава името на прожекцията.  */
    std::string get_name();
    /** \return Дава залата на прожекцията.  */
    Hall get_hall();
};

std::ostream& operator<< (std::ostream&, std::vector<Event>); /**< Позволява вкарването на информация за прожекции от файл в системата. */
std::istream& operator>> (std::istream&, std::vector<Event>&); /**< Позволява извеждането на информация за прожекции от системата във файл. */

#endif