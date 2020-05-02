#ifndef LINE_H
#define LINE_H

#include "Figure.h"

class Line : public Figure {
private:
    double x1, y1, x2, y2;
    std::string color;
public:
    Line(double _x1, double _y1, double _x2, double _y2, std::string _color);

    void print();
    void translate(double tX, double tY);
    bool within(double wX, double wY, double wR);
    bool within(double wX, double wY, double wW, double wH);

    void write(std::ostream &os);
};

#endif