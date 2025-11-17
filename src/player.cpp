#include "player.hpp"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& n) : name(n) {}
Player::Player(const Player& other) : name(other.name), hand(other.hand) {}

Player& Player::operator=(const Player& other) {
    name = other.name;
    hand = other.hand;
    return *this;
}

bool Player::operator==(const Player& other) const {
    if (name != other.name) return false;
    if (hand.size() != other.hand.size()) return false;
    for (size_t i = 0; i < hand.size(); ++i) {
        if (*(hand[i]) != *(other.hand[i])) return false;
    }
    return true;
}

void Player::addCard(CardPtr card) {
    hand.push_back(card);
}

void Player::removeCard(int index) {
    if (index >= 0 && index < static_cast<int>(hand.size()))
        hand.erase(hand.begin() + index);
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (auto& card : hand)
        std::cout << card->shortString() << " ";
    std::cout << std::endl;
}

int Player::handSize() const {
    return static_cast<int>(hand.size());
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.getName() << "'s hand: ";
    for (auto& c : player.getHand())
        out << c->shortString() << " ";
    return out;
}

std::istream& operator>>(std::istream& in, Player& player) {
    int count;
    in >> count;
    for (int i = 0; i < count; ++i) {
        int s, r;
        in >> s >> r;
        player.addCard(std::make_shared<Card>(static_cast<Suit>(s), static_cast<Rank>(r)));
    }
    return in;
}
