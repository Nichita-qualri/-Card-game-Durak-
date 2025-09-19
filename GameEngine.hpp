#pragma once
#include <vector>
#include "Deck.cpp"
#include "Player.hpp"

struct GameEngine {
	Deck deck;
	std::vector<Player> players;
};
