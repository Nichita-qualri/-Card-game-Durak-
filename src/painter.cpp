#pragma once
#include "abstract_painter.hpp"
#include <iostream>
#include <string>

class Painter : public AbstractPainter {
public:
    void DrawImage(Point topLeft, Point bottomRight, char** image) override {
        std::cout << "Drawing image from (" << topLeft.x << "," << topLeft.y << ") "
            << "to (" << bottomRight.x << "," << bottomRight.y << ")" << std::endl;
    }
    void WriteText(Point position, const std::string& text) override {
        std::cout << "Text at (" << position.x << "," << position.y << "): " << text << std::endl;
    }
};
