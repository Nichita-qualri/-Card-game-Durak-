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
