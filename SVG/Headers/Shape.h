#ifndef SHAPE_H
#define SHAPE_H

#include "Stroke.h"

#include <iostream>
#include <vector>

class Rectangle;
class Circle;

/**
 * Клас Shape.
 * Класът Shape е изцяло виртуален клас, използва се за да може да се определят
 * различните фигури, че са от този вид, както и да може да се съхраняват заедно. 
 * Shape съдържа цвят на дадената фигура, както и подчертаваща линия (Stroke). 
 * Наследниците на класа имат изискване за поддържането на виртуалните методи на този клас.
 */

class Shape {
private:
    Color color; /**< Цвят на фигурата. */
protected:
    Stroke stroke; /**< Подчертаваща линия на фигурата. */
public:

    /**
     * Конструктор за класа Shape. 
     * Конструкторът приема променливи, които се поддържат от всяка фигура от SVG.
     * Наследниците на Shape, имат цвят с който се изобразяват в равнината, 
     * и подчертаваща линия, която е също с цвят и широчина на щриха.
     */
    Shape(Color _color, Color _stroke_color = Transperant, double _stroke_width = 0) : color(_color), stroke(_stroke_color, _stroke_width) {}

    virtual void print() = 0; /**< Метода се използва за извеждане на информация за обекта наследник в конзолата. */
    virtual void translate(double, double) = 0; /**< Променя разположението на обекта наследник в равнината по подадено изместване по ординатата и абцисата.*/
    virtual bool within(const Rectangle&) = 0; /**< Проверява дали дадения обект наследник се намира изцяло в друг обект Rectangle с дадени параметри. */
    virtual bool within(const Circle&) = 0; /**< Проверява дали дадения обект наследник се намира изцяло в друг обект Circle с дадени параметри. */
    virtual void write(std::ostream&) = 0; /**< Метода се използва за записване на информацията на обекта наследник във файл. */

    /** \return Дава цвета на фигурата. */
    Color get_color() const;
};

std::ostream& operator<< (std::ostream&, const std::vector<Shape*>); /**< Позволява вкарването на информация за фигури от файл в системата. */
std::istream& operator>> (std::istream&, std::vector<Shape*>&); /**< Позволява извеждането на информация за фигури от системата във файл. */

#endif