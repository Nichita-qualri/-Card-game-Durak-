#pragma once
#include "Suit.hpp"
#include "Rank.hpp"
#include <string>

class Card {
	Suit suit;
	Rank rank;
	bool isTrump;

public:
    Card(Suit suit, Rank rank, bool isTrump);

    std::string toString() const;
    bool beats(const Card& other) const;
    std::string shortString() const;

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }
    bool getIsTrump() const { return isTrump; }
};;