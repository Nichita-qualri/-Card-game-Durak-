#include "Rank.hpp"

const char* RankHelper::ToString(Rank rank) {
    switch (rank) {
    case Rank::Six:   return "Six";
    case Rank::Seven: return "Seven";
    case Rank::Eight: return "Eight";
    case Rank::Nine:  return "Nine";
    case Rank::Ten:   return "Ten";
    case Rank::Jack:  return "Jack";
    case Rank::Queen: return "Queen";
    case Rank::King:  return "King";
    case Rank::Ace:   return "Ace";
    default:          
    return "Unknown";
    }
}
