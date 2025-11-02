#pragma once
#include <vector>
#include <memory>
#include "Deck.hpp"
#include "Player.hpp"

class GameEngine {
    Deck deck;
    std::vector<PlayerPtr> players;
public:
    GameEngine();
    void run();
    void addPlayer(PlayerPtr player);
};
