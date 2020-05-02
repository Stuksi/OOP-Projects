#include "Headers\Rectangle.h"

Rectangle::Rectangle(double _x, double _y, double _width, double _height, std::string _color) : x(_x), y(_y), width(_width), height(_height), color(_color) {}

void Rectangle::print() {
    std::cout << "Rectangle - " << "x: \"" << x << "\" ,y: \"" << y << "\" ,width: \"" 
              << width << "\" ,height: \"" << height  << "\" ,color: \"" << color << "\"." << std::endl;
}

void Rectangle::translate(double tX, double tY) {
    x += tX;
    y += tY;
}

bool Rectangle::within(double wX, double wY, double wR) {
    return wX + wR >= x + width
        && wY + wR >= y + height
        && wX - wR <= x
        && wY - wR <= y;
}

bool Rectangle::within(double wX, double wY, double wW, double wH) {
    return wX + wW >= x + width
        && wY + wH >= y + height
        && wX <= x
        && wY <= y;
}

void Rectangle::write(std::ostream &os) {
    os << "<rect x=\"" << x << "\" y=\"" << y  << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << color << "\" />\n";
}