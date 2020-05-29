#ifndef FACTORY_H
#define FACTORY_H

#include "Shape.h"

#include <string>

/**
 * @class Factory
 * A class helper, to recognise the class type.
 */

class Factory {
private:
    static void to_lower_case (std::string& type);

public:
    static Color find_color(std::string);
    static std::string color_to_string(Color);
    static Shape* get_shape (std::vector<std::string> shape_info);

    static std::string top_file, bottom_file;
};

#endif