#pragma once 
#include "Card.hpp"

Card::Card(Suit s, Rank r) : suit(s), rank(r) {}

std::string Card::toString() const {
	return "Card(" + std::to_string(static_cast<int>(suit)) + ", " + std::to_string(static_cast<int>(rank)) + ")";
}	