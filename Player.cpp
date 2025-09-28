#include "Player.hpp"
#include <iostream>

void Player::addCard(Card card) {
	hand.push_back(card);
}

void Player::removeCard(int index) {
	hand.erase(hand.begin() + index);
}

void Palyer::showHand() {
	std::cout << name << "'s hand: ";
}

int Player::handSize() {
	return hand.size();
}