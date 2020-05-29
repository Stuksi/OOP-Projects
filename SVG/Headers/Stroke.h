#ifndef STROKE_H
#define STROKE_H

// Enum to define some basic color values.
enum Color {
    Transperant,
    Red,
    Green,
    Blue,
    Black,
    White,
    Orange,
    Pink,
    Purple,
    Cyan,
    Brown,
    Lime
};

/**
 * @class Stroke
 * Class representing the stroke over the shape.
 * @param stroke_color
 * Defines the color of the stroke.
 * @param stroke_width
 * Defines the width of the stroke.
 * @fn Color Stroke::get_color()
 * Accessing the "stroke_color" parameter.
 * @fn Color Stroke::get_width()
 * Accessing the "stroke_width" parameter.
 */

class Stroke {
private:
    Color stroke_color;
    double stroke_width;
public:
    Stroke(Color _stroke_color = Transperant, double _stroke_width = 0) : stroke_color(_stroke_color), stroke_width(_stroke_width) {}

    Color get_color() const { return stroke_color; };
    double get_width() const { return stroke_width; };
};

#endif