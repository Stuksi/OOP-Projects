#include "..\Headers\Line.h"
#include "..\Headers\Rectangle.h"
#include "..\Headers\Circle.h"
#include "..\Headers\Factory.h"

/**
 * @fn void Line::print()
 * Prints in the terminal the shape parameters.
 * @fn void Line::translate()
 * Offsets the shape in a certain direction.
 * @fn bool Line::within(const Rectangle& rectangle)
 * Check whether a shape is inside the range of a rectangle.
 * @fn bool Line::within(const Circle& circle)
 * Check whether a shape is inside the range of a circle.
 * @fn void Line::write()
 * Output information of the shape to a stream. 
 */

void Line::print() {
    std::cout << "Line: x1 = \""
              << x1 << "\", y1 = \""
              << y1 << "\", x2 = \""
              << x2 << "\", y2 = \""
              << y2 << "\"";
    if(stroke.get_width() != 0) {
        std::cout << ", stroke-color = \"" << Factory::color_to_string(stroke.get_color()) << "\"";
        std::cout << ", stroke-width = \"" << stroke.get_width() << "\"";
    }
    std::cout << "." << std::endl;
}

void Line::translate(double horizontal_translation = 0, double vertical_translation = 0) {
    x1 += horizontal_translation;
    x2 += horizontal_translation;
    y1 += vertical_translation;
    y2 += vertical_translation;
}

bool Line::within(const Rectangle& rectangle) {
    return x1 >= rectangle.get_x()
        && x2  <= rectangle.get_x() + rectangle.get_width()
        && y1 >= rectangle.get_y()
        && y2 <= rectangle.get_y() + rectangle.get_height();
}

bool Line::within(const Circle& circle) {
    return x1 >= circle.get_cx() - circle.get_r()
        && x2 <= circle.get_cx() + circle.get_r()
        && y1 >= circle.get_cy() - circle.get_r()
        && y2 <= circle.get_cy() + circle.get_r();
}

void Line::write(std::ostream& os) {
    os << "<line x1=\"" << x1
       << "\" y1=\"" << y1
       << "\" x2=\"" << x2
       << "\" y2=\"" << y2;
    if(stroke.get_width() != 0) {
        os << "\" stroke=\"" << Factory::color_to_string(stroke.get_color())
           << "\" stroke-width=\"" << stroke.get_width();
    }
    os << "\" />\n";
}