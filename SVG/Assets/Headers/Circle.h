#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
private:
    double cx, cy, r;
    std::string color;
public:
    Circle(double _cx, double _cy, double _r, std::string _color);

    void print();
    void translate(double tX, double tY);
    bool within(double wX, double wY, double wR);
    bool within(double wX, double wY, double wW, double wH);

    void write(std::ostream &os);
};

#endif