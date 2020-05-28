#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

/**
 * @param cx
 * The cx property describes the horizontal center coordinate of the position of the circle.
 * @param cy
 * The cy property describes the vertical center coordinate of the position of the circle.
 * @param r
 * The r property describes the radius of the circle.
 */

class Circle : public Shape {
private:
    double cx, cy, r;
public:
    Circle(double _cx, double _cy, double _r, Color _color, Color _stroke_color = Transperant, double _stroke_width = 0)
    : cx(_cx), cy(_cy), r(_r), Shape(_color, _stroke_color, _stroke_width) {}

    void print();
    void translate(double, double);
    bool within(const Rectangle&);
    bool within(const Circle&);
    void write(std::ostream&);

    double get_cx() const;
    double get_cy() const;
    double get_r() const;
};

#endif