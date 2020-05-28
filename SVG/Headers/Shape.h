#ifndef SHAPE_H
#define SHAPE_H

#include "Stroke.h"

#include <iostream>
#include <vector>

/**
 * @class Shape
 * Pure virtual class, base class. 
 * @param color 
 * Represents the color/filling of the shape.
 * @param stroke
 * Represents the stroke object over the shape.
 * @fn void print()
 * Prints in the terminal the shape parameters.
 * @fn void translate()
 * Offsets the shape in a certain direction.
 * @fn bool within(const Rectangle& rectangle)
 * Check whether a shape is inside the range of a rectangle.
 * @fn bool within(const Circle& circle)
 * Check whether a shape is inside the range of a circle.
 * @fn void write()
 * Output information of the shape to a stream. 
 * @fn std::ostream& operator<< ()
 * Used to write information of shapes to a stream.
 * @fn std::istream& operator>> ()
 * Used to read from a stream to an array of shapes.
 */

class Rectangle;
class Circle;

class Shape {
private:
    Color color;
protected:
    Stroke stroke;
public:
    Shape(Color _color, Color _stroke_color = Transperant, double _stroke_width = 0) : color(_color), stroke(_stroke_color, _stroke_width) {}
    
    virtual void print() = 0;
    virtual void translate(double, double) = 0;
    virtual bool within(const Rectangle&) = 0;
    virtual bool within(const Circle&) = 0;
    virtual void write(std::ostream&) = 0;

    Color get_color() const;
};

std::ostream& operator<< (std::ostream&, const std::vector<Shape*>);
std::istream& operator>> (std::istream&, std::vector<Shape*>&);

#endif