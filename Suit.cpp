#include "Suit.hpp"

const char* SuitHelper::ToString(Suit suit) {
    switch (suit) {
    case Suit::Hearts:   return "Hearts";
    case Suit::Diamonds: return "Diamonds";
    case Suit::Clubs:    return "Clubs";
    case Suit::Spades:   return "Spades";
    default: return "Unknown";
    }
}
