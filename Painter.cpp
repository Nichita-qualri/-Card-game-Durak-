#include "Painter.hpp"
#include <iostream>

void Painter::DrawImage(Point topLeft, Point bottomRight, char** image) {
    std::cout << "DrawImage from (" << topLeft.x << "," << topLeft.y
        << ") to (" << topLeft.x << "," << topLeft.y << ")\n";
}

void Painter::WriteText(Point position, char* text) {
    std::cout << "WriteText at (" << position.x << "," << position.y
        << "): " << text << std::endl;
}
