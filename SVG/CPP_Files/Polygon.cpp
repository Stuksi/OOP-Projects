#include "..\Headers\Polygon.h"
#include "..\Headers\Rectangle.h"
#include "..\Headers\Circle.h"
#include "..\Headers\Factory.h"

void Polygon::print() {
    std::cout << "Polygon: Points {";
    for (size_t i = 0; i < x_points.size(); i++)
    {
        std::cout << " \"" << x_points[i] << "," << y_points[i] << "\" ";
    }
    std::cout << "}, color = \"" << Factory::color_to_string(get_color()) << "\"";
    if(stroke.get_width() != 0) {
        std::cout << ", stroke-color = \"" << Factory::color_to_string(stroke.get_color()) << "\"";
        std::cout << ", stroke-width = \"" << stroke.get_width() << "\"";
    }
    std::cout << "." << std::endl;
}

void Polygon::translate(double horizontal_translation = 0, double vertical_translation = 0) {
    for (size_t i = 0; i < x_points.size(); i++)
    {
        x_points[i] += horizontal_translation;
        y_points[i] += vertical_translation;
    }
}

bool Polygon::within(const Rectangle& rectangle) {
    double minX = INT32_MAX, maxX = INT32_MIN, minY = INT32_MAX, maxY = INT32_MIN;
    for (size_t i = 0; i < x_points.size(); i++)
    {
        if(x_points[i] < minX) {
            minX = x_points[i];
        }
        if(x_points[i] > maxX) {
            maxX = x_points[i];
        }
        if(y_points[i] < minY) {
            minY = y_points[i];
        }
        if(y_points[i] > maxY) {
            maxY = y_points[i];
        }
    }
    return minX >= rectangle.get_x()
        && maxX  <= rectangle.get_x() + rectangle.get_width()
        && minY >= rectangle.get_y()
        && maxX <= rectangle.get_y() + rectangle.get_height();
}

bool Polygon::within(const Circle& circle) {
    double minX = INT32_MAX, maxX = INT32_MIN, minY = INT32_MAX, maxY = INT32_MIN;
    for (size_t i = 0; i < x_points.size(); i++)
    {
        if(x_points[i] < minX) {
            minX = x_points[i];
        }
        if(x_points[i] > maxX) {
            maxX = x_points[i];
        }
        if(y_points[i] < minY) {
            minY = y_points[i];
        }
        if(y_points[i] > maxY) {
            maxY = y_points[i];
        }
    }
    return minX >= circle.get_cx() - circle.get_r()
        && maxX <= circle.get_cx() + circle.get_r()
        && minY >= circle.get_cy() - circle.get_r()
        && maxY <= circle.get_cy() + circle.get_r();
}

void Polygon::write(std::ostream& os) {
    os << "<polygon fill=\"" << Factory::color_to_string(get_color());
    if(stroke.get_width() != 0) {
        os << "\" stroke=\"" << Factory::color_to_string(stroke.get_color())
           << "\" stroke-width=\"" << stroke.get_width();
    }
    os << "\" points=\"";
    for (size_t i = 0; i < x_points.size(); i++)
    {
        os << " " << x_points[i] << "," << y_points[i] << " ";
    }
    os << "\" />\n";
}