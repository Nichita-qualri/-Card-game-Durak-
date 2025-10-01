#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine() {}

void GameEngine::Run() {
	deck.shuffle();
	// To do: deal cards to players
	deck.setTrumpSuit();
	Suit trump = deck.getTrumpSuit();
	std::cout << "Game initialized with trump suit: " << static_cast<int>(trump) << std::endl;
}

void GameEngine::addPlayer(const Player& player) {
	players.push_back(player);
}