#pragma once
#include <string>

struct Point {
    int x;
    int y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct AbstractPainter {
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;
    virtual void WriteText(Point position, const std::string& text) = 0;
};
