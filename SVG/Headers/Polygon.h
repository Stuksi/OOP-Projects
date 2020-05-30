#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

#include <vector>

/**
 * Клас Polygon.
 * Класът Polygon наследява класа Shape. Той съдържа допълнителни променливи,
 * като "програмистки" вектори от координатите на точките на многоъгълниката по ординатата и абцисата.
 */

class Polygon : public Shape {
private:
    std::vector<double> x_points; /**< Координатите на точките по абцисата. */
    std::vector<double> y_points; /**< Координатите на точките по ординатата. */
public:

    /**
     * Конструктор за класа Polygon. 
     * Конструкторът приема допълнителни променливите необходими за съществуването на един многоъгълник в равнината, 
     * като координатите на точките образуващи фигурата. Polygon може да има и цвят, както
     * и подчертаваща линия, която е също с цвят и широчина на щриха. Тези компоненти са наследени
     * от класа Shape. 
     */
    Polygon(std::vector<double> _x_points, std::vector<double> _y_points, Color _color, Color _stroke_color = Transperant, double _stroke_width = 0)
    : x_points(_x_points), y_points(_y_points), Shape(_color, _stroke_color, _stroke_width) {}

    void print(); /**< Метода се използва за извеждане на информация за обекта в конзолата. */
    void translate(double, double); /**< Променя разположението на обекта в равнината по подадено изместване по ординатата и абцисата. 
                                         Метода влияе само на координатите на точките образуващи многоъгълника.*/
    bool within(const Rectangle&); /**< Проверява дали дадения обект се намира изцяло в друг обект Rectangle с дадени параметри. */
    bool within(const Circle&); /**< Проверява дали дадения обект се намира изцяло в друг обект Circle с дадени параметри. */
    void write(std::ostream&); /**< Метода се използва за записване на информацията на обекта във файл. */
};

#endif