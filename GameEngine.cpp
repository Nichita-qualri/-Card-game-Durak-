#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine() {}

void GameEngine::run() {
    deck.shuffle();
    deck.setTrumpSuit();
    Suit trump = deck.getTrumpSuit();
    std::cout << "Trump suit: " << static_cast<int>(trump) << std::endl;

    for (auto& player : players) {
        for (int i = 0; i < 6; ++i) {
            CardPtr card = deck.dealCard();
            if (card) player->addCard(card);
        }
        player->showHand();
    }
}

void GameEngine::addPlayer(PlayerPtr player) {
    players.push_back(player);
}
