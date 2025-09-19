#pragma once

#include <vector>
#include "Card.cpp"
#include <string>

struct Player {
	std::string name;
	std::vector<Card> hand;

    void addCard(Card card);    
    void removeCard(int index); 
    void showHand();            
    int handSize();
};