#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <vector>

/*
    Класът фигура е абстрактрният клас който всички останали фигури наследяват.
    Той задава функциите които всяка фигура трябва да поддържа.
*/

class Figure {
public:
    // Функцията print извежда в терминала информация за фигурата.
    virtual void print() = 0;
    // Функцията translate променя местоположението на фигурата в равнината при подадено отместване.
    virtual void translate(double tX, double tY) = 0;
    // Функцията within(circle) проверява дали дадената фигура се намира в обсега на кръг с въведените координати.
    virtual bool within(double wX, double wY, double wR) = 0;
    // Функцията within(rectangle) проверява дали дадената фигура се намира в обсега на правоъгълник с въведените координати.
    virtual bool within(double wX, double wY, double wW, double wH) = 0;

    // Функцията write се използва за правилно записване на информацията.
    virtual void write(std::ostream &os) = 0;
};

// Operator>> се използва за възможмо четене на информация от файл.
std::istream &operator >> (std::istream &is, std::vector<Figure *>& figures);
// Operator<< се използва за възможмо записване на информация във файл.
std::ostream &operator << (std::ostream &os, const std::vector<Figure *>& figures);

#endif