#pragma once
#pragma once
#include "Card.hpp"
#include "Player.hpp"
#include <iostream>

struct AbstractPainter {
    virtual void DrawImage(int x, int y, char** image) = 0;
    virtual void WriteText(int x, int y, const std::string& text) = 0;
};

