#ifndef CMD_H
#define CMD_H

#include "Event.h"

#include <vector>
#include <fstream>

/** Клас CMD.
 *  Класът CMD е помощен клас, който се използва за извикване
 *  и обработка на различните функции, които програмата трябва 
 *  да поддържа с цел да е отделно от програмата която прочита 
 *  входа от конзолата.
 */

class CMD {
private:
    static bool exists (std::string); /**< Проверява дали даден файл съществува по името на файла. (Stack Overflow) */
    static bool empty_file (std::string); /**< Проверява дали даден файл е празен по името на файла. (Stack Overflow) */
public:
    static void open(std::ifstream&, std::vector<Event>&, std::string&); /**< Отваря даден файл и записва информацията за фигурите от него в системата. */
    static void close(std::ifstream&, std::vector<Event>&, std::string&); /**< Затваря отворения файл и изчиства информацията му от системата. */
    static void save(std::ifstream&, std::vector<Event>&, std::string); /**< Запазва обработената от системата информация в същия файл, който е отворен. */
    static void saveas(std::ifstream&, std::vector<std::string>, std::vector<Event>&); /**< Запазва обработената от системата информация във файл посочен от потребителя по име.
                                                                                            Ако този файл не съществува, се създава нов с това име. */
    static void help (); /**< Извежда информация за всички поддържани от програмата команди. */
    
    static void add_event(std::vector<std::string>, std::vector<Event>&); /**< Добавя нова прожекция в системата. */
    static void free_seats(std::vector<std::string>, std::vector<Event>&); /**< Извежда информация за свободните места на дадена прожекция в терминала. */
    static void access_seats(std::vector<std::string>, std::vector<Event>&, std::vector<int>&, int); /**< Позволява да се закупи, запази или освободи място. */
    static void bookings(std::vector<std::string>, std::vector<Event>&); /**< Извежда във файл информация за запазените места на посочена прожекция/и. */
    static void check(std::vector<std::string>, std::vector<Event>&, std::vector<int>&); /**< Проверява по даден код на билет дали съответства място в зала. */
    static void report(std::vector<std::string>, std::vector<Event>&); /**< Извежда във файл информация за закупените места на посочена прожекция/и. */
};

#endif