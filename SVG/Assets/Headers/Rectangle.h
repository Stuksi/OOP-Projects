#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

/*
    Класът правоъгълник, съдържа основните атрибути на един правоъгълник от геометрията
    в координатна система Оху (координати на точка и дължина и 
    височина на правоъгълника : x, y, width, height), по условието 
    на задачата е зададен и низ с който да илюстрирам цвета
    на фигурата. Класът поддържа всички нужни команди от условието на задачата,
    като проверките са различни от другите класове тъй като е различна фигура.
*/

class Rectangle : public Figure {
private:
    double x, y, width, height;
    std::string color;
public:
    Rectangle(double _x, double _y, double _width, double _height, std::string _color);

    void print();
    void translate(double tX, double tY);
    bool within(double wX, double wY, double wR);
    bool within(double wX, double wY, double wW, double wH);

    void write(std::ostream &os);
};

#endif