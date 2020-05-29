#include "..\Headers\Shape.h"
#include "..\Headers\Factory.h"
#include "..\Headers\Line.h"
#include "..\Headers\Rectangle.h"
#include "..\Headers\Circle.h"
#include "..\Headers\Polygon.h"

#include <functional>

/**
 * @fn std::ostream& operator<< ()
 * Used to write information of shapes to a stream.
 * @fn std::istream& operator>> ()
 * Used to read from a stream to an array of shapes.
 */

Color Shape::get_color() const {
    return color; 
};

std::ostream& operator<< (std::ostream& os, const std::vector<Shape*> shapes) {
    os << Factory::top_file;
    os << "<svg>\n";
    for (size_t i = 0; i < shapes.size(); i++)
    {
        shapes[i]->write(os);
    }
    os << Factory::bottom_file;
    return os;
}

std::istream& operator>> (std::istream& is, std::vector<Shape*>& shapes) {
    
    std::string input, file_info = "";
    bool flag = false;

    while (std::getline(is, input))
    {
        file_info += input;
        file_info += "\n";
    }

    double values[10];
    Color shape_color = Transperant, stroke_color = Transperant;
    std::vector<double> x_points, y_points;

    std::function<void(size_t&, std::vector<double>&, std::vector<double>&)> string_to_vectors = 
        [file_info](size_t& i, std::vector<double>& x_points, std::vector<double>& y_points)->void {
        std::string result = "";
        while (file_info[i] != '"')
        {   
            if(file_info[i] != ' ' && file_info[i] != ',') {
                result+=file_info[i];
            }
            i++;
            if((file_info[i] == ' ' || file_info[i] == '"') && result != "") {
                y_points.push_back(stod(result));
                result = "";
            }
            if(file_info[i] == ',' && result != "") {
                x_points.push_back(stod(result));
                result = "";
            }  
        }
    };

    std::function<double(size_t&)> string_to_double = [file_info](size_t& i)->double {
        std::string result = "";
        while (file_info[i] != '"')
        {
            result+=file_info[i];
            i++;
        }
        return stod(result);
    };

    std::function<Color(size_t&)> string_to_color = [file_info](size_t& i)->Color {
        std::string result = "";
        while (file_info[i] != '"')
        {
            result+=file_info[i];
            i++;
        }
        return Factory::find_color(result);
    };

    for (size_t i = 0; i < file_info.length(); i++)
    {
        if(file_info[i] == '<' && file_info[i+1] == 's' && file_info[i+2] == 'v'
        && file_info[i+3] == 'g' && file_info[i+4] == '>') {
            flag = true;
            while(file_info[i] != '<' || file_info[i+1] != '/' || file_info[i+2] != 's'
            || file_info[i+3] != 'v' || file_info[i+4] != 'g' || file_info[i+5] != '>') {
                if(file_info[i] == '<') {
                    // Reset parameters
                    for (size_t j = 0; j < 10; j++)
                    {
                        values[j] = 0;
                    }
                    shape_color = stroke_color = Transperant;
                    x_points.clear();
                    y_points.clear();
                    
                    i++;
                    // Rectangle
                    if(file_info[i] == 'r' && file_info[i+1] == 'e' 
                    && file_info[i+2] == 'c' && file_info[i+3] == 't') {
                        while (file_info[i] != '/' || file_info[i+1] != '>')
                        { 
                            if(file_info[i] == 'x' && file_info[i+1] == '='
                            && file_info[i+2] == '"') {
                                i+=3;
                                values[0] = string_to_double(i);
                            } else if(file_info[i] == 'y'&& file_info[i+1] == '='
                                && file_info[i+2] == '"') {
                                i+=3;
                                values[1] = string_to_double(i);
                            } else if(file_info[i] == 'w' && file_info[i+1] == 'i'
                                && file_info[i+2] == 'd' && file_info[i+3] == 't' 
                                && file_info[i+4] == 'h' && file_info[i+5] == '='
                                && file_info[i+6] == '"') {
                                i+=7;
                                values[2] = string_to_double(i);
                            } else if(file_info[i] == 'h' && file_info[i+1] == 'e'
                                && file_info[i+2] == 'i' && file_info[i+3] == 'g' 
                                && file_info[i+4] == 'h' && file_info[i+5] == 't'
                                && file_info[i+6] == '=' && file_info[i+7] == '"') {
                                i+=8;
                                values[3] = string_to_double(i);
                            } else if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o' 
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '-' && file_info[i+7] == 'w' 
                                && file_info[i+8] == 'i' && file_info[i+9] == 'd'
                                && file_info[i+10] == 't' && file_info[i+11] == 'h'
                                && file_info[i+12] == '=' && file_info[i+13] == '"') {
                                i+=14;
                                values[6] = string_to_double(i);
                            } else if(file_info[i] == 'r' && file_info[i+1] == 'x'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[4] = string_to_double(i);
                            } else if(file_info[i] == 'r' && file_info[i+1] == 'y'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[5] = string_to_double(i);
                            } else if(file_info[i] == 'f' && file_info[i+1] == 'i'
                                && file_info[i+2] == 'l' && file_info[i+3] == 'l'
                                && file_info[i+4] == '=' && file_info[i+5] == '"') {
                                i+=6;
                                shape_color = string_to_color(i);
                            } else if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o'
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '=' && file_info[i+7] == '"') {
                                i+=8;
                                stroke_color = string_to_color(i);
                            }
                            i++;     
                        }
                        shapes.push_back(new Rectangle(values[0], values[1], values[2], values[3], shape_color, values[4], values[5], stroke_color, values[6]));
                    // Circle
                    } else if(file_info[i] == 'c' && file_info[i+1] == 'i'
                    && file_info[i+2] == 'r' && file_info[i+3] == 'c'
                    && file_info[i+4] == 'l' && file_info[i+5] == 'e') {
                        while (file_info[i] != '/' && file_info[i+1] != '>')
                        {
                            if(file_info[i] == 'r' && file_info[i+1] == '='
                            && file_info[i+2] == '"') {
                                i+=3;
                                values[2] = string_to_double(i);
                            } else if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o' 
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '-' && file_info[i+7] == 'w' 
                                && file_info[i+8] == 'i' && file_info[i+9] == 'd'
                                && file_info[i+10] == 't' && file_info[i+11] == 'h'
                                && file_info[i+12] == '=' && file_info[i+13] == '"') {
                                i+=14;
                                values[3] = string_to_double(i);
                            } else if(file_info[i] == 'c' && file_info[i+1] == 'x'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[0] = string_to_double(i);
                            } else if(file_info[i] == 'c' && file_info[i+1] == 'y'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[1] = string_to_double(i);
                            } else if(file_info[i] == 'f' && file_info[i+1] == 'i'
                                && file_info[i+2] == 'l' && file_info[i+3] == 'l'
                                && file_info[i+4] == '=' && file_info[i+5] == '"') {
                                i+=6;
                                shape_color = string_to_color(i);
                            } else if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o'
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '=' && file_info[i+7] == '"') {
                                i+=8;
                                stroke_color = string_to_color(i);
                            }   
                            i++;  
                        }
                        shapes.push_back(new Circle(values[0], values[1], values[2], shape_color, stroke_color, values[6]));
                    // Line
                    } else if(file_info[i] == 'l' && file_info[i+1] == 'i'
                    && file_info[i+2] == 'n' && file_info[i+3] == 'e') {
                        while (file_info[i] != '/' && file_info[i+1] != '>')
                        {
                            if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o' 
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '-' && file_info[i+7] == 'w' 
                                && file_info[i+8] == 'i' && file_info[i+9] == 'd'
                                && file_info[i+10] == 't' && file_info[i+11] == 'h'
                                && file_info[i+12] == '=' && file_info[i+13] == '"') {
                                i+=14;
                                values[4] = string_to_double(i);
                            } else if(file_info[i] == 'x' && file_info[i+1] == '1'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[0] = string_to_double(i);
                            } else if(file_info[i] == 'y' && file_info[i+1] == '1'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[1] = string_to_double(i);
                            } else if(file_info[i] == 'x' && file_info[i+1] == '2'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[2] = string_to_double(i);
                            } else if(file_info[i] == 'y' && file_info[i+1] == '2'
                                && file_info[i+2] == '=' && file_info[i+3] == '"') {
                                i+=4;
                                values[3] = string_to_double(i);
                            } else if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o'
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '=' && file_info[i+7] == '"') {
                                i+=8;
                                stroke_color = string_to_color(i);
                            }     
                            i++;
                        }
                        shapes.push_back(new Line(values[0], values[1], values[2], values[3], stroke_color, values[4]));
                    // Polygon
                    } else if(file_info[i] == 'p' && file_info[i+1] == 'o' && file_info[i+2] == 'l' 
                    && file_info[i+3] == 'y' && file_info[i+4] == 'g' && file_info[i+5] == 'o' && file_info[i+6] == 'n') {
                        while (file_info[i] != '/' && file_info[i+1] != '>')
                        {
                            if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o'
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '=' && file_info[i+7] == '"') {
                                i+=8;
                                stroke_color = string_to_color(i);
                            } else if(file_info[i] == 'f' && file_info[i+1] == 'i'
                                && file_info[i+2] == 'l' && file_info[i+3] == 'l'
                                && file_info[i+4] == '=' && file_info[i+5] == '"') {
                                i+=6;
                                shape_color = string_to_color(i);
                            } else if(file_info[i] == 'p' && file_info[i+1] == 'o'
                                && file_info[i+2] == 'i' && file_info[i+3] == 'n'
                                && file_info[i+4] == 't' && file_info[i+5] == 's'
                                && file_info[i+6] == '=' && file_info[i+7] == '"') {
                                i+=8;
                                string_to_vectors(i, x_points, y_points);
                            } else if(file_info[i] == 's' && file_info[i+1] == 't'
                                && file_info[i+2] == 'r' && file_info[i+3] == 'o' 
                                && file_info[i+4] == 'k' && file_info[i+5] == 'e'
                                && file_info[i+6] == '-' && file_info[i+7] == 'w' 
                                && file_info[i+8] == 'i' && file_info[i+9] == 'd'
                                && file_info[i+10] == 't' && file_info[i+11] == 'h'
                                && file_info[i+12] == '=' && file_info[i+13] == '"') {
                                i+=14;
                                values[0] = string_to_double(i);    
                            }
                            i++;
                        }
                        shapes.push_back(new Polygon(x_points, y_points, shape_color, stroke_color, values[0]));
                    }
                }
                i++;
            }
        }
        if(!flag) {
            Factory::top_file += file_info[i];
        } else {
            Factory::bottom_file += file_info[i];
        }
    }
    return is;
}
