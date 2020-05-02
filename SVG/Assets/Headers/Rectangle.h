#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    double x, y, width, height;
    std::string color;
public:
    Rectangle(double _x, double _y, double _width, double _height, std::string _color);

    void print();
    void translate(double tX, double tY);
    bool within(double wX, double wY, double wR);
    bool within(double wX, double wY, double wW, double wH);

    void write(std::ostream &os);
};

#endif