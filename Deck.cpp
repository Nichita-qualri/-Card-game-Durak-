#include "Deck.hpp"
#include <random>
#include <chrono>
#include <iostream>

Deck::Deck() {}
Deck::Deck(const Deck& other) : cards(other.cards), trumpSuit(other.trumpSuit) {}

Deck& Deck::operator=(const Deck& other) {
    cards = other.cards;
    trumpSuit = other.trumpSuit;
    return *this;
}

bool Deck::operator==(const Deck& other) const {
    if (cards.size() != other.cards.size()) return false;
    for (size_t i = 0; i < cards.size(); ++i)
        if (*(cards[i]) != *(other.cards[i])) return false;
    return trumpSuit == other.trumpSuit;
}

void Deck::shuffle() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

CardPtr Deck::dealCard() {
    if (cards.empty()) return nullptr;
    CardPtr c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::isEmpty() const { return cards.empty(); }
int Deck::size() const { return static_cast<int>(cards.size()); }
void Deck::addCard(CardPtr card) { cards.push_back(card); }

void Deck::setTrumpSuit() {
    if (!cards.empty())
        trumpSuit = cards.back()->getSuit();
}
Suit Deck::getTrumpSuit() const { return trumpSuit; }

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (auto& c : deck.cards)
        out << *c << " ";
    return out;
}

std::istream& operator>>(std::istream& in, Deck& deck) {
    int count;
    in >> count;
    for (int i = 0; i < count; ++i) {
        int s, r;
        in >> s >> r;
        deck.addCard(std::make_shared<Card>(static_cast<Suit>(s), static_cast<Rank>(r)));
    }
    return in;
}
