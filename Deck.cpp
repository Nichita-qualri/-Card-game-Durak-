#include "Deck.hpp"

Deck::Deck() {}

Deck::Deck(const Deck& other) : cards(other.cards), trumpSuit(other.trumpSuit) {}

Deck Deck::operator=(const Deck& other) {
    cards = other.cards;
    trumpSuit = other.trumpSuit;
    return *this;
}

bool Deck::operator==(const Deck& other) const {
    return cards == other.cards && trumpSuit == other.trumpSuit;
}

void Deck::shuffle() {
    // Todo implementarea shuffle
}

Card Deck::dealCard() {
    Card c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::isEmpty() const { return cards.empty(); }

int Deck::size() const { return static_cast<int>(cards.size()); }

void Deck::setTrumpSuit() {
    if (!cards.empty()) {
        trumpSuit = cards.back().getSuit();
    }
}

void Deck::addCard(const Card& card) {
    cards.push_back(card);
}

std::istream& operator>>(std::istream& in, Deck& deck) {
    int n;
    in >> n;
    deck.cards.clear();
    for (int i = 0; i < n; i++) {
        Card c;
        in >> c;
        deck.addCard(c);
    }
    deck.setTrumpSuit();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (auto& c : deck.cards)
        out << c << " ";
    return out;
}
