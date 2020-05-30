#ifndef FACTORY_H
#define FACTORY_H

#include "Shape.h"

#include <string>

/**
 * Клас Factory.
 * Класът Factory е помощен клас, който съдържа методи за определяне
 * на вида на дадена фигура по подаден низ, както и опеделяне на
 * цвят.
 */

class Factory {
private:
    static void to_lower_case (std::string& type); /**< Помощен метод за променяне на низа да е изцяло
                                                        с малки букви за по-лесна обработка от програмата. */

public:
    static Color find_color(std::string); /**< Открива цвета по подаден низ. */
    static std::string color_to_string(Color); /**< Открива низа по цвят. */
    static Shape* get_shape (std::vector<std::string> shape_info); /**< Открива типа на фигурата и нейните атрибути по подаден вектор от низове. */

    static std::string top_file; /**< Съдържа текста над инфорамацията с фигурите, на файла който е отворен. */
    static std::string bottom_file; /**< Съдържа текста под инфорамацията с фигурите, на файла който е отворен. */
};

#endif