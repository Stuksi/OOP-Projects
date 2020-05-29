#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

#include <vector>

class Polygon : public Shape {
private:
    std::vector<double> x_points;
    std::vector<double> y_points;
public:
    Polygon(std::vector<double> _x_points, std::vector<double> _y_points, Color _color, Color _stroke_color = Transperant, double _stroke_width = 0)
    : x_points(_x_points), y_points(_y_points), Shape(_color, _stroke_color, _stroke_width) {}

    void print();
    void translate(double, double);
    bool within(const Rectangle&);
    bool within(const Circle&);
    void write(std::ostream&);
};

#endif