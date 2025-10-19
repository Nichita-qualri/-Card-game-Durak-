#pragma once
#include "Suit.hpp"
#include "Rank.hpp"
#include <iostream>
#include <string>

class Card {
    Suit suit;
    Rank rank;
    bool isTrump;

public:
    Card();
    Card(Suit suit, Rank rank, bool isTrump);
    Card(const Card& other);

    Card operator=(const Card& other);
    bool operator==(const Card& other) const;

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }
    bool getIsTrump() const { return isTrump; }
    std::string shortString() const;
    bool beats(const Card& other) const;
};

std::istream& operator>>(std::istream& in, Card& card);
std::ostream& operator<<(std::ostream& out, const Card& card);
