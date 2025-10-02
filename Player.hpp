#pragma once
#include <vector>
#include <string>
#include "Card.hpp"

struct Player {
    std::string name;
    std::vector<Card> hand;

    void addCard(const Card& card);    
    void removeCard(int index);        
    void showHand() const;             
    int handSize() const;              
};
