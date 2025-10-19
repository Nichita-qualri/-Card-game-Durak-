#pragma once
#include "Deck.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>

class GameEngine {
    Deck deck;
    std::vector<Player> players;

public:
    GameEngine();
    GameEngine(const GameEngine& other);

    GameEngine operator=(const GameEngine& other);
    bool operator==(const GameEngine& other) const;

    void Run();
    void addPlayer(const Player& player);
};

std::istream& operator>>(std::istream& in, GameEngine& engine);
std::ostream& operator<<(std::ostream& out, const GameEngine& engine);
