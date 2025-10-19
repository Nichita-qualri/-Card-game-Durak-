#include "Card.hpp"

Card::Card() : suit(Suit::Hearts), rank(Rank::Six), isTrump(false) {}

Card::Card(Suit s, Rank r, bool trump) : suit(s), rank(r), isTrump(trump) {}

Card::Card(const Card& other) : suit(other.suit), rank(other.rank), isTrump(other.isTrump) {}

Card Card::operator=(const Card& other) {
    suit = other.suit;
    rank = other.rank;
    isTrump = other.isTrump;
    return *this;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && rank == other.rank && isTrump == other.isTrump;
}

std::string Card::shortString() const {
    std::string ranks = "6789JQKA";
    std::string suits = "♠♣♥♦";
    return std::string(1, ranks[static_cast<int>(rank)]) + suits[static_cast<int>(suit)];
}

bool Card::beats(const Card& other) const {
    if (isTrump && !other.isTrump) return true;
    if (!isTrump && other.isTrump) return false;
    if (suit == other.suit && rank > other.rank) return true;
    return false;
}

std::istream& operator>>(std::istream& in, Card& card) {
    int s, r;
    bool trump;
    in >> s >> r >> trump;
    card = Card(static_cast<Suit>(s), static_cast<Rank>(r), trump);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.shortString();
    return out;
}
