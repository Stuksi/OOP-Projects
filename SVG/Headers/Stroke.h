#ifndef STROKE_H
#define STROKE_H

/**
 * Поддържаните цветове от програмата.
 */
enum Color {
    Transperant, /**< Безцветен */
    Red, /**< Червен */
    Green, /**< Зелен */
    Blue, /**< Син */
    Black, /**< Черен */
    White, /**< Бял */
    Orange, /**< Оранжев */
    Pink, /**< Розов */
    Purple, /**< Лилав */
    Cyan, /**< Тюркоаз */
    Brown, /**< Кафяв */
    Lime /**< Светло Зелен */
};

/**
 * Клас Stroke.
 * Класът Stroke представлява подчертаващата линия на всеки обект(Shape).
 * Stroke може да има цвят и широчина на щриха.
 */

class Stroke {
private:
    Color stroke_color; /**< Цвят на подчертаващата линия. */
    double stroke_width; /**< Ширина на щриха на подчертаващата линия. */
public:

    /**
     * Конструктор за класа Stroke. 
     * Конструкторът приема променливи, от които е изградена една подчертаваща линия.
     * Stroke имат цвят с който се изобразяват около фигурата, 
     * и широчина на линията.
     */
    Stroke(Color _stroke_color = Transperant, double _stroke_width = 0) : stroke_color(_stroke_color), stroke_width(_stroke_width) {}

    /** \return Дава цвета на подчертаващата линия. */
    Color get_color() const { return stroke_color; };
    /** \return Дава ширината на подчертаващата линия. */
    double get_width() const { return stroke_width; };
};

#endif