#ifndef LINE_H
#define LINE_H

#include "Shape.h"

/**
 * @param x1
 * The coordinate on the 'x' axis of the start of the line.
 * @param y1
 * The coordinate on the 'y' axis of the start of the line.
 * @param x2
 * The coordinate on the 'x' axis of the end of the line.
 * @param y2
 * The coordinate on the 'y' axis of the end of the line.
 */

class Line : public Shape {
private:
    double x1, y1, x2, y2;
public:
    Line(double _x1, double _y1, double _x2, double _y2, Color _stroke_color = Transperant, double _stroke_width = 0)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2), Shape(Transperant, _stroke_color, _stroke_width) {}

    void print();
    void translate(double, double);
    bool within(const Rectangle&);
    bool within(const Circle&);
    void write(std::ostream&);
};

#endif