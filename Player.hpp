#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Card.hpp"

class Player {
    std::string name;
    std::vector<CardPtr> hand;
public:
    Player(const std::string& n);
    Player(const Player& other);

    void addCard(CardPtr card);
    void removeCard(int index);
    void showHand() const;
    int handSize() const;

    Player& operator=(const Player& other);
    bool operator==(const Player& other) const;

    const std::string& getName() const { return name; }
    const std::vector<CardPtr>& getHand() const { return hand; }
};

std::ostream& operator<<(std::ostream& out, const Player& player);
std::istream& operator>>(std::istream& in, Player& player);
using PlayerPtr = std::shared_ptr<Player>;
