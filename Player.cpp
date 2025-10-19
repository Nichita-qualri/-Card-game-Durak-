#include "Player.hpp"
#include <iostream>

Player::Player() : name("Player") {}

Player::Player(const std::string& n) : name(n) {}

Player::Player(const Player& other) : name(other.name), hand(other.hand) {}

Player Player::operator=(const Player& other) {
    name = other.name;
    hand = other.hand;
    return *this;
}

bool Player::operator==(const Player& other) const {
    return name == other.name && hand == other.hand;
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::removeCard(int index) {
    if (index >= 0 && index < hand.size()) {
        hand.erase(hand.begin() + index);
    }
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (const auto& c : hand)
        std::cout << c << " ";
    std::cout << std::endl;
}

int Player::handSize() const {
    return static_cast<int>(hand.size());
}

std::istream& operator>>(std::istream& in, Player& player) {
    in >> player.name;
    int n;
    in >> n;
    player.hand.clear();
    for (int i = 0; i < n; i++) {
        Card c;
        in >> c;
        player.addCard(c);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.getName() << ": ";
    for (const auto& c : player.hand)
        out << c << " ";
    return out;
}