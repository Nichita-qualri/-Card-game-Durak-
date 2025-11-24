#pragma once
#include <vector>
#include <memory>
#include "deck.hpp"
#include "player.hpp"

class GameEngine {
    Deck deck;
    std::vector<PlayerPtr> players;

    int getPlayerChoice(PlayerPtr player, bool allowTake = false);
    bool canBeat(CardPtr defense, CardPtr attack, Suit trump);

public:
    GameEngine();
    void run();
    void addPlayer(PlayerPtr player);
};