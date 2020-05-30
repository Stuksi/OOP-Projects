#ifndef COMMAND_PROMPT_H
#define COMMAND_PROMPT_H

#include "Shape.h"
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
    static void open (std::vector<Shape *>&, std::ifstream&, std::string&); /**< Отваря даден файл и записва информацията за фигурите от него в системата. */
    static void close (std::vector<Shape *>&, std::ifstream&, std::string&); /**< Затваря отворения файл и изчиства информацията му от системата. */
    static void save (std::vector<Shape *>&, std::ifstream&, std::string&); /**< Запазва обработената от системата информация в същия файл, който е отворен. */
    static void saveas (std::vector<Shape *>&, std::vector<std::string>, std::ifstream&); /**< Запазва обработената от системата информация във файл посочен от потребителя по име.
                                                                                               Ако този файл не съществува, се създава нов с това име. */
    static void help (); /**< Извежда информация за всички поддържани от програмата команди. */
    static void parameters (); /**< Извежда информация за всички фигури и параметрите които имат. */

    static void print (std::vector<Shape *>&); /**< Извежда информацията на всички фигури в системата в терминала. */
    static void create (std::vector<Shape *>&, std::vector<std::string>); /**< Създава нова фигура по подаден низ. */
    static void erase (std::vector<Shape *>&, std::vector<std::string>); /**< Изтрива дадена фигура по подаден пореден номер. */
    static void translate (std::vector<Shape *>&, std::vector<std::string>); /**< Измества дадена фигура(всички фигури) по подадени параметри за преместване. */
    static void within (std::vector<Shape *>&, std::vector<std::string>); /**< Извежда всички фигури, които са в даден обсег посочен от потребителя. */
};
#endif