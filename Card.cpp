#include "Card.hpp"
#include <string>

Card::Card(Suit suit, Rank rank, bool isTrump)
    : suit(suit), rank(rank), isTrump(isTrump) {
}

std::string Card::toString() const {
    return "Card(" + std::to_string(static_cast<int>(suit)) + ", "
        + std::to_string(static_cast<int>(rank)) + ")";
}

bool Card::beats(const Card& other) const {
    if (isTrump && !other.isTrump) return true;
    if (!isTrump && other.isTrump) return false;
    if (suit == other.suit && rank > other.rank) return true;
    return false;
}

std::string Card::shortString() const {
    std::string ranks = "6789JQKA";
    std::string suits = "♠♣♥♦";
    return std::string(1, ranks[static_cast<int>(rank)]) + suits[static_cast<int>(suit)];
}
