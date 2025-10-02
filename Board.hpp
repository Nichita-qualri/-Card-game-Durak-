#pragma once

class Board {
    int _width;
    int _height;
    int _length;

public:
    Board(int width = 90, int height = 150, int length = 75);

    int GetWidth() const;
    int GetHeight() const;
    int GetLength() const;
};