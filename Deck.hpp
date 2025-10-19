#pragma once
#include <vector>
#include "Card.hpp"
#include <iostream>

class Deck {
    std::vector<Card> cards;
    Suit trumpSuit;

public:
    Deck();
    Deck(const Deck& other);

    Deck operator=(const Deck& other);
    bool operator==(const Deck& other) const;

    void shuffle();
    Card dealCard();
    bool isEmpty() const;
    int size() const;

    Suit getTrumpSuit() const { return trumpSuit; }
    void setTrumpSuit();
    void addCard(const Card& card);
};

std::istream& operator>>(std::istream& in, Deck& deck);
std::ostream& operator<<(std::ostream& out, const Deck& deck);
