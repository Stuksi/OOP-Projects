#include "..\Headers\Rectangle.h"
#include "..\Headers\Circle.h"
#include "..\Headers\Factory.h"

void Rectangle::print() {
    std::cout << "Rectangle: x = \""
              << x << "\", y = \""
              << y << "\", width = \""
              << width << "\", height = \""
              << height << "\"";
    if(rx != 0) {
        std::cout << ", rx = \"" << rx << "\"";
    }
    if(ry != 0) {
        std::cout << ", ry = \"" << ry << "\"";
    }
    std::cout << ", color = \"" << Factory::color_to_string(get_color()) << "\"";
    if(stroke.get_width() != 0) {
        std::cout << ", stroke-color = \"" << Factory::color_to_string(stroke.get_color()) << "\"";
        std::cout << ", stroke-width = \"" << stroke.get_width() << "\"";
    }
    std::cout << "." << std::endl;
}

void Rectangle::translate(double horizontal_translation = 0, double vertical_translation = 0) {
    x += horizontal_translation;
    y += vertical_translation;
}

bool Rectangle::within(const Rectangle& rectangle) {
    return x >= rectangle.x
        && x + width <= rectangle.x + rectangle.width
        && y >= rectangle.y
        && y + height <= rectangle.y + rectangle.height;
}

bool Rectangle::within(const Circle& circle) {
    return x >= circle.get_cx() - circle.get_r()
        && x + width <= circle.get_cx() + circle.get_r()
        && y >= circle.get_cy() - circle.get_r()
        && y + height <= circle.get_cy() + circle.get_r();
}

void Rectangle::write(std::ostream& os) {
    os << "<rect x=\"" << x
       << "\" y=\"" << y
       << "\" width=\"" << width
       << "\" height=\"" << height
       << "\" fill=\"" << Factory::color_to_string(get_color());
    if(stroke.get_width() != 0) {
        os << "\" stroke=\"" << Factory::color_to_string(stroke.get_color())
           << "\" stroke-width=\"" << stroke.get_width();
    }
    os << "\" />\n";
}

double Rectangle::get_x() const {
    return x;
}

double Rectangle::get_y() const {
    return y;
}

double Rectangle::get_width() const {
    return width;
}

double Rectangle::get_height() const {
    return height;
}