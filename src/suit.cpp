#include "suit.hpp"

const char* SuitHelper::ToString(Suit suit) {
    switch (suit) {
    case Suit::Hearts:   return "Hearts";
    case Suit::Diamonds: return "Diamonds";
    case Suit::Clubs:    return "Clubs";
    case Suit::Spades:   return "Spades";
    default: return "Unknown";
    }
}

const char* SuitHelper::ToSymbol(Suit suit) {
    switch (suit) {
    case Suit::Hearts:   return "♥";
    case Suit::Diamonds: return "♦";
    case Suit::Clubs:    return "♣";
    case Suit::Spades:   return "♠";
    default: return "?";
    }
}