#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <vector>

class Figure {
public:
    virtual void print() = 0;
    virtual void translate(double tX, double tY) = 0;
    virtual bool within(double wX, double wY, double wR) = 0;
    virtual bool within(double wX, double wY, double wW, double wH) = 0;

    virtual void write(std::ostream &os) = 0;
};

std::istream &operator >> (std::istream &is, std::vector<Figure *>& figures);
std::ostream &operator << (std::ostream &os, const std::vector<Figure *>& figures);

#endif