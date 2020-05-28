#include "..\Headers\Circle.h"
#include "..\Headers\Rectangle.h"
#include "..\Headers\Factory.h"

void Circle::print() {
    std::cout << "Circle: cx = \""
              << cx << "\", cy = \""
              << cy << "\", r = \""
              << r << "\"";
    std::cout << ", color = \"" << Factory::color_to_string(get_color()) << "\"";
    if(stroke.get_width() != 0) {
        std::cout << ", stroke-color = \"" << Factory::color_to_string(stroke.get_color()) << "\"";
        std::cout << ", stroke-width = \"" << stroke.get_width() << "\"";
    }
    std::cout << "." << std::endl;
}

void Circle::translate(double horizontal_translation = 0, double vertical_translation = 0) {
    cx += horizontal_translation;
    cy += vertical_translation;
}

bool Circle::within(const Rectangle& rectangle) {
    return cx - r >= rectangle.get_x()
        && cx + r <= rectangle.get_x() + rectangle.get_width()
        && cy - r >= rectangle.get_y()
        && cy + r <= rectangle.get_y() + rectangle.get_height();
}

bool Circle::within(const Circle& circle) {
    return cx - r >= circle.cx - circle.r
        && cx + r <= circle.cx + circle.r
        && cy - r >= circle.cy - circle.r
        && cy + r <= circle.cy + circle.r;
}

void Circle::write(std::ostream& os) {
    os << "<circle cx=\"" << cx
       << "\" cy=\"" << cy
       << "\" r=\"" << r
       << "\" fill=\"" << Factory::color_to_string(get_color());
    if(stroke.get_width() != 0) {
        os << "\" stroke=\"" << Factory::color_to_string(stroke.get_color())
           << "\" stroke-width=\"" << stroke.get_width();
    }
    os << "\" />\n";
}

double Circle::get_cx() const {
    return cx;
}

double Circle::get_cy() const {
    return cy;
}

double Circle::get_r() const {
    return r;
}
