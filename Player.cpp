#include "Player.hpp"
#include <iostream>

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::removeCard(int index) {
    if (index >= 0 && index < hand.size()) {
        hand.erase(hand.begin() + index);
    }
    else {
        std::cout << "Invalid card index!" << std::endl;
    }
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (const auto& card : hand) {
        std::cout << card.shortString() << " ";
    }
    std::cout << std::endl;
}

int Player::handSize() const {
    return static_cast<int>(hand.size());
}
