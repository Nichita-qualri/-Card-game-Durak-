#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine() {}

void GameEngine::Init() {
	deck.shuffle();
	std::cout << "Game initialized with " << std::endl;
}

void GameEngine::Run() {
	std::cout << "Game started with " << std::endl;
	}
void GameEngine::addPlayer(const Player& player) {
	players.push_back(player);
}