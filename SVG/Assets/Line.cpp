#include "Headers\Line.h"

Line::Line(double _x1, double _y1, double _x2, double _y2, std::string _color) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), color(_color) {}

void Line::print() {
    std::cout << "Line - " << "x1: \"" << x1 << "\" ,y1: \"" << y1 << "\" ,x2: \"" 
              << x2 << "\" ,y2: \"" << y2  << "\" ,color: \"" << color << "\"." << std::endl;
}

void Line::translate(double tX, double tY) {
    x1 += tX;
    x2 += tX;
    y1 += tY;
    y2 += tY;
}

bool Line::within(double wX, double wY, double wR) {
    return wX + wR >= std::max(x1, x2)
        && wY + wR >= std::max(y1, y2)
        && wX - wR <= std::min(x1, x2)
        && wY - wR <= std::min(y1, y2);
}

bool Line::within(double wX, double wY, double wW, double wH) {
    return wX + wW >= std::max(x1, x2)
        && wY + wH >= std::max(y1, y2)
        && wX <= std::min(x1, x2)
        && wY <= std::min(y1, y2);
}

void Line::write(std::ostream &os) {
    os << "<line x1=\"" << x1 << "\" y1=\"" << y1  << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" fill=\"" << color << "\" />\n";
}