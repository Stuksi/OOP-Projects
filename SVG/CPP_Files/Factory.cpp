#include "..\Headers\Factory.h"
#include "..\Headers\Rectangle.h"
#include "..\Headers\Circle.h"
#include "..\Headers\Line.h"
#include "..\Headers\Polygon.h"

void Factory::to_lower_case (std::string& type) {
    for (size_t i = 0; i < type.length(); i++)
    {
        if(type[i] >= 'A' && type[i] <= 'Z') {
            type[i] += 'a' - 'A';
        }
    }
}

Color Factory::find_color(std::string color_init) {
    to_lower_case(color_init);
    Color color = Transperant;
    if(color_init == "transperant") {
        color = Transperant;
    } else if(color_init == "red") {
        color = Red;
    } else if(color_init == "green") {
        color = Green;
    } else if(color_init == "blue") {
        color = Blue;
    } else if(color_init == "black") {
        color = Black;
    } else if(color_init == "white") {
        color = White;
    } else if(color_init == "orange") {
        color = Orange;
    } else if(color_init == "brown") {
        color = Brown;
    } else if(color_init == "pink") {
        color = Pink;
    } else if(color_init == "purple") {
        color = Purple;
    } else if(color_init == "cyan") {
        color = Cyan;
    } else if(color_init == "lime") {
        color = Lime;
    }
    return color;
}

std::string Factory::color_to_string(Color color) {
    switch (color)
    {
    case 0:
        return "Transperant";
        break;
    case 1:
        return "Red";
        break;
    case 2:
        return "Green";
        break;
    case 3:
        return "Blue";
        break;
    case 4:
        return "Black";
        break;
    case 5:
        return "White";
        break;
    case 6:
        return "Orange";
        break;
    case 7:
        return "Pink";
        break;
    case 8:
        return "Purple";
        break;
    case 9:
        return "Cyan";
        break;
    case 10:
        return "Brown";
        break;
    case 11:
        return "Lime";
        break;
    }
    return "";
}

Shape* Factory::get_shape (std::vector<std::string> shape_info) {
    Shape* new_shape = nullptr;
    to_lower_case(shape_info[0]);
    if(shape_info[0] == "rect" || shape_info[0] == "rectangle") {
        if(shape_info.size() == 5) {
            new_shape = new Rectangle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), stod(shape_info[4]), Transperant);
        } else if(shape_info.size() == 6) {
            new_shape = new Rectangle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), stod(shape_info[4]), find_color(shape_info[5]));
        } else if(shape_info.size() == 8) {
            new_shape = new Rectangle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), stod(shape_info[4]), find_color(shape_info[5]), stod(shape_info[6]), stod(shape_info[7]));
        } else if(shape_info.size() == 10) {
            new_shape = new Rectangle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), stod(shape_info[4]), find_color(shape_info[5]), stod(shape_info[6]), stod(shape_info[7]), find_color(shape_info[8]), stod(shape_info[9]));
        }
    } else if(shape_info[0] == "circle") {
        if(shape_info.size() == 4) {
            new_shape = new Circle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), Transperant);
        } else if(shape_info.size() == 5) {
            new_shape = new Circle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), find_color(shape_info[4]));
        } else if(shape_info.size() == 7) {
            new_shape = new Circle(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), find_color(shape_info[4]), find_color(shape_info[5]), stod(shape_info[6]));
        }
    } else if(shape_info[0] == "line") {
        if(shape_info.size() == 5) {
            new_shape = new Line(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), stod(shape_info[4]));
        } else if(shape_info.size() == 7){
            new_shape = new Line(stod(shape_info[1]), stod(shape_info[2]), stod(shape_info[3]), stod(shape_info[4]), find_color(shape_info[5]), stod(shape_info[6]));
        }
    } else if(shape_info[0] == "polygon") {
        std::string result = "";
        std::vector<double> x_values, y_values;
        size_t i = 1;

        while (i < shape_info.size())
        {
            if(shape_info[i][0] < '0' || shape_info[i][0] > '9') {
                break;
            }
            for (size_t j = 0; j < shape_info[i].length(); j++)
            {  
                if(shape_info[i][j] != ',') {
                    result+=shape_info[i][j];
                } else {
                    x_values.push_back(stod(result));
                    result = "";
                }
                if(shape_info[i][j+1] == '\0' && result != "") {
                    y_values.push_back(stod(result));
                    result = "";
                }
            }   
            i++;     
        }
        if(shape_info.size() == i) {
            new_shape = new Polygon(x_values, y_values, Transperant);
        } else if(shape_info.size() == i + 1) {
            new_shape = new Polygon(x_values, y_values, find_color(shape_info[i]));
        } else if(shape_info.size() == i + 3) {
            new_shape = new Polygon(x_values, y_values, find_color(shape_info[i]), find_color(shape_info[i+1]), stod(shape_info[i+2]));
        }
    }
    return new_shape;
}