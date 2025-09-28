#pragma once
#include "Suit.hpp"
#include "Rank.hpp"
#include <string>

struct Card {
	Suit suit;
	Rank rank;

	Card(Suit s, Rank r);
	std::string toString() const;
};