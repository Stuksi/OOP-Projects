#ifndef LINE_H
#define LINE_H

#include "Figure.h"

/*
    Класът линия, съдържа основните атрибути на една линия от геометрията
    в координатна система Оху (координати на две точки в равнината : x1, y1, x2, y2),
    по условието на задачата е зададен и низ с който да илюстрирам цвета
    на фигурата. Класът поддържа всички нужни команди от условието на задачата,
    като проверките са различни от другите класове тъй като е различна фигура.
*/

class Line : public Figure {
private:
    double x1, y1, x2, y2;
    std::string color;
public:
    Line(double _x1, double _y1, double _x2, double _y2, std::string _color);

    void print();
    void translate(double tX, double tY);
    bool within(double wX, double wY, double wR);
    bool within(double wX, double wY, double wW, double wH);

    void write(std::ostream &os);
};

#endif