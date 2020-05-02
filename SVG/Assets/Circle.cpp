#include "Headers\Circle.h"

Circle::Circle(double _cx, double _cy, double _r, std::string _color) : cx(_cx), cy(_cy), r(_r), color(_color) {}

void Circle::print() {
    std::cout << "Circle - " << "cx: \"" << cx << "\" ,cy: \"" << cy << "\" ,r: \"" 
              << r << "\" ,color: \"" << color << "\"." << std::endl;
}

void Circle::translate(double tX, double tY) {
    cx += tX;
    cy += tY;
}

bool Circle::within(double wX, double wY, double wR) {
    return wX + wR >= cx + r
        && wY + wR >= cy + r
        && wX - wR <= cx - r
        && wY - wR <= cy - r;
}

bool Circle::within(double wX, double wY, double wW, double wH) {
    return wX + wW >= cx + r
        && wY + wH >= cy + r
        && wX <= cx - r
        && wY <= cy - r;
}

void Circle::write(std::ostream &os) {
    os << "<circle cx=\"" << cx << "\" cy=\"" << cy  << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
}