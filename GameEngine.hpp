#pragma once
#include <vector>
#include "Deck.hpp"
#include "Player.hpp"

struct GameEngine {
    Deck deck;
    std::vector<Player> players;

public:
    GameEngine();
    void Run();
    void addPlayer(const Player& player);
};
