#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "Card.hpp"

class Deck {
    std::vector<CardPtr> cards;
    Suit trumpSuit;
public:
    Deck();
    Deck(const Deck& other);

    void shuffle();
    CardPtr dealCard();
    bool isEmpty() const;
    int size() const;
    void addCard(CardPtr card);
    void setTrumpSuit();
    Suit getTrumpSuit() const;

    Deck& operator=(const Deck& other);
    bool operator==(const Deck& other) const;
};

std::ostream& operator<<(std::ostream& out, const Deck& deck);
std::istream& operator>>(std::istream& in, Deck& deck);
