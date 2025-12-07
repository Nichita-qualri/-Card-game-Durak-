/**
 * @file painter.hpp
 * @brief Concrete painter implementation
 * @project Durak Card Game
 * @author Nichita-qualri
 * @date 2025
 */

#pragma once
#include "abstract_painter.hpp"
#include <iostream>

class Painter : public AbstractPainter {
public:
    void DrawImage(Point topLeft, Point bottomRight, char** image);
    void WriteText(Point, const std::string&);
};
