#ifndef FACTORY_H
#define FACTORY_H

#include "Shape.h"

#include <string>

/**
 * @class Factory
 * A class helper, to recognise the class type.
 * @fn Color find_color()
 * Color recognision from string.
 * @fn std::string color_to_string()
 * Color to string.
 * @fn void to_lower_case()
 * Changes the string to lower case.
 */

class Factory {
private:
    static void to_lower_case (std::string& type);
public:
    static Color find_color(std::string);
    static std::string color_to_string(Color);
    static Shape* get_shape (std::vector<std::string> shape_info);
};

#endif