#pragma once
#include <vector>
#include "Card.hpp"

class Deck {
    std::vector<Card> cards;
	Suit trumpSuit;

public:
    Deck();
    void shuffle();
    Card dealCard();
    bool isEmpty() const;
    int size() const;
    Suit getTrumpSuit() const { return cards.back().getSuit(); }
    void setTrumpSuit() const { trumpSuit = cards.back().getSuit(); }
    void AddCard(const Card& card);
};

