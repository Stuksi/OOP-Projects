#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

/**
 * @param x
 * The x property describes the horizontal coordinate of the position of the element.
 * @param y
 * The y property describes the vertical coordinate of the position of the element.
 * @param width
 * This property specifies the width of the rectangle.
 * Negative values for 'width' are illegal.
 * @param height
 * This property specifies the height of the rectangle.
 * Negative values for 'height' are illegal.
 * @param rx
 * The rx property describes the horizontal curve radius of the rectangle.
 * A negative value for rx is illegal.
 * @param ry
 * The ry property describes the vertical curve radius of the rectangle.
 * A negative value for ry is illegal.
 */

class Rectangle : public Shape {
private:
    double x, y, rx, ry, width, height;
public:
    Rectangle(double _x, double _y, double _width, double _height, Color _color, double _rx = 0, double _ry = 0, Color _stroke_color = Transperant, double _stroke_width = 0) 
    : x(_x), y(_y), width(_width), height(_height), rx(_rx), ry(_ry), Shape(_color, _stroke_color, _stroke_width) {}
    
    void print();
    void translate(double, double);
    bool within(const Rectangle&);
    bool within(const Circle&);
    void write(std::ostream&);

    double get_x() const;
    double get_y() const;
    double get_width() const;
    double get_height() const;
};

#endif