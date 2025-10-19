#pragma once
#include <string>
#include <vector>
#include "Card.hpp"
#include <iostream>

class Player {
    std::string name;
    std::vector<Card> hand;

public:
    Player();
    Player(const std::string& name);
    Player(const Player& other);

    Player operator=(const Player& other);
    bool operator==(const Player& other) const;

    void addCard(const Card& card);
    void removeCard(int index);
    void showHand() const;
    int handSize() const;
    std::string getName() const { return name; }
};

std::istream& operator>>(std::istream& in, Player& player);
std::ostream& operator<<(std::ostream& out, const Player& player);
