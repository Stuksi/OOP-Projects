#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

/**
 * Клас Circle.
 * Класът Circle наследява класа Shape. Той съдържа допълнителни променливи,
 * като координати на центъра в равнината и дължина нарадиуса.
 */

class Circle : public Shape {
private:
    double cx; /**< Координатата на центъра на кръга по абцисата. */
    double cy; /**< Координатата на центъра на кръга по ординатата. */
    double r; /**< Дължината на радиуса на кръга. */
public:

    /**
     * Конструктор за класа Circle. 
     * Конструкторът приема допълнителни променливите необходими за съществуването на един кръг в равнината, 
     * като координатите на центъра му и дължината на радиуса. Circle може да има и цвят, както
     * и подчертаваща линия, която е също с цвят и широчина на щриха. Тези компоненти са наследени
     * от класа Shape. 
     */
    Circle(double _cx, double _cy, double _r, Color _color, Color _stroke_color = Transperant, double _stroke_width = 0)
    : cx(_cx), cy(_cy), r(_r), Shape(_color, _stroke_color, _stroke_width) {}

    void print(); /**< Метода се използва за извеждане на информация за обекта в конзолата. */
    void translate(double, double); /**< Променя разположението на обекта в равнината по подадено изместване по ординатата и абцисата. 
                                         Метода влияе само на координатите на центъра на обекта.*/
    bool within(const Rectangle&); /**< Проверява дали дадения обект се намира изцяло в друг обект Rectangle с дадени параметри. */
    bool within(const Circle&); /**< Проверява дали дадения обект се намира изцяло в друг обект Circle с дадени параметри. */
    void write(std::ostream&); /**< Метода се използва за записване на информацията на обекта във файл. */

    /** \return Дава координатата по абцисата на центъра на Circle. */
    double get_cx() const; 
    /** \return Дава координатата по ординатата на центъра на Circle. */
    double get_cy() const; 
    /** \return Дава дължината на радиуса на Circle. */
    double get_r() const; 
};

#endif