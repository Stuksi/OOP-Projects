#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

/*
    Класът кръг, съдържа основните атрибути на един кръг от геометрията
    в координатна система Оху (координати на центъра и радиус : cx, cy, r),
    по условието на задачата е зададен и низ с който да илюстрирам цвета
    на фигурата. Класът поддържа всички нужни команди от условието на задачата,
    като проверките са различни от другите класове тъй като е различна фигура.
*/

class Circle : public Figure {
private:
    double cx, cy, r;
    std::string color;
public:
    Circle(double _cx, double _cy, double _r, std::string _color);

    void print();
    void translate(double tX, double tY);
    bool within(double wX, double wY, double wR);
    bool within(double wX, double wY, double wW, double wH);

    void write(std::ostream &os);
};

#endif