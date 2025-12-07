/**
 * @file rank.hpp
 * @brief Card rank enumeration and utilities
 * @project Durak Card Game
 * @author Nichita-qualri
 * @date 2025
 */

#pragma once

enum class Rank {
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class RankHelper {
public:
    RankHelper() {}  
    static const char* ToString(Rank rank); 
};
