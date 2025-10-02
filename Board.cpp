#include "Board.hpp"

Board::Board(int width, int height, int length)
    : _width(width), _height(height), _length(length) {
}

int Board::GetWidth() const {
    return _width;
}

int Board::GetHeight() const {
    return _height;
}

int Board::GetLength() const {
    return _length;
}
