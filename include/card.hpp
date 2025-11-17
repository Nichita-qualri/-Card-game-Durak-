#pragma once
#include <string>
#include <memory>
#include "suit.hpp"
#include "rank.hpp"

class Card {
    Suit suit;
    Rank rank;
    bool isTrump;
public:
    Card(Suit suit, Rank rank, bool isTrump = false);
    Card(const Card& other);

    std::string toString() const;
    bool beats(const Card& other) const;
    std::string shortString() const;

    Card& operator=(const Card& other);
    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const;

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }
    bool getIsTrump() const { return isTrump; }
};

std::ostream& operator<<(std::ostream& out, const Card& card);
std::istream& operator>>(std::istream& in, Card& card);
using CardPtr = std::shared_ptr<Card>;
