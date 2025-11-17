#include "painter.hpp"
#include <iostream>
#include <string>

void Painter::DrawImage(Point topLeft, Point bottomRight, char** image) {
    std::cout << "Drawing image from (" << topLeft.x << "," << topLeft.y << ") "
        << "to (" << bottomRight.x << "," << bottomRight.y << ")" << std::endl;
}

void Painter::WriteText(Point position, const std::string& text) {
    std::cout << "Text at (" << position.x << "," << position.y << "): " << text << std::endl;
}