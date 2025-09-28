#pragma once
#include <vector>
#include "Card.hpp"

class Deck {
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card dealCard();
    bool isEmpty() const;
    int size() const;
    void AddCard(const Card& card);
};

