#pragma once

#include <vector>
#include "Card.cpp"
#include <string>

struct Player {
	std::string name;
	std::vector<Card> hand;
};