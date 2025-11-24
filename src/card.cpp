#include "card.hpp"
#include <iostream>

Card::Card(Suit s, Rank r, bool trump) : suit(s), rank(r), isTrump(trump) {}

Card::Card(const Card& other) : suit(other.suit), rank(other.rank), isTrump(other.isTrump) {}

Card& Card::operator=(const Card& other) {
    suit = other.suit;
    rank = other.rank;
    isTrump = other.isTrump;
    return *this;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && rank == other.rank && isTrump == other.isTrump;
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

bool Card::operator<(const Card& other) const {
    if (isTrump != other.isTrump) return isTrump > other.isTrump;
    if (suit == other.suit) return static_cast<int>(rank) < static_cast<int>(other.rank);
    return static_cast<int>(suit) < static_cast<int>(other.suit);
}

std::string Card::toString() const {
    return "Card(" + std::to_string(static_cast<int>(suit)) + ", " + std::to_string(static_cast<int>(rank)) + ")";
}

std::string Card::shortString() const {
    std::string ranks = "6789TJQKA";

    std::string suitSymbol;
    switch (suit) {
    case Suit::Spades:   suitSymbol = "♠"; break;  
    case Suit::Clubs:    suitSymbol = "♣"; break;  
    case Suit::Hearts:   suitSymbol = "♥"; break;  
    case Suit::Diamonds: suitSymbol = "♦"; break;  
    }

    return std::string(1, ranks[static_cast<int>(rank)]) + suitSymbol;
}

bool Card::beats(const Card& other) const {
    if (isTrump && !other.isTrump) return true;
    if (!isTrump && other.isTrump) return false;
    if (suit == other.suit && rank > other.rank) return true;
    return false;
}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Card& card) {
    int s, r;
    in >> s >> r;
    card = Card(static_cast<Suit>(s), static_cast<Rank>(r));
    return in;
}