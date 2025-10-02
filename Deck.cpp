#include "Deck.hpp"

Deck::Deck() {
}

void Deck::shuffle() {
    // To do
}

Card Deck::dealCard() {
    Card c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::isEmpty() const {
    return cards.empty();
}

int Deck::size() const {
    return static_cast<int>(cards.size());
}

void Deck::AddCard(const Card& card) {
    cards.push_back(card);
}
