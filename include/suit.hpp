/**
 * @file suit.hpp
 * @brief Card suit enumeration and utilities
 * @project Durak Card Game
 * @author Nichita-qualri
 * @date 2025
 */

#pragma once

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

class SuitHelper {
public:
    SuitHelper() {}
    static const char* ToString(Suit suit);
    static const char* ToSymbol(Suit suit);
};