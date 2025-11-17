#pragma once
#include <vector>
#include <memory>
#include "deck.hpp"
#include "player.hpp"

class GameEngine {
    Deck deck;
    std::vector<PlayerPtr> players;
public:
    GameEngine();
    void run();
    void addPlayer(PlayerPtr player);
};
