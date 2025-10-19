#include "GameEngine.hpp"

GameEngine::GameEngine() {}

GameEngine::GameEngine(const GameEngine& other)
    : deck(other.deck), players(other.players) {
}

GameEngine GameEngine::operator=(const GameEngine& other) {
    deck = other.deck;
    players = other.players;
    return *this;
}

bool GameEngine::operator==(const GameEngine& other) const {
    return deck == other.deck && players == other.players;
}

void GameEngine::Run() {
    deck.shuffle();
    deck.setTrumpSuit();
    Suit trump = deck.getTrumpSuit();
    std::cout << "Game initialized with trump suit: " << static_cast<int>(trump) << std::endl;

    //Se poate de adaugat logica pentru impartire cartilor jucatorilor dar mai pe urma 
}

void GameEngine::addPlayer(const Player& player) {
    players.push_back(player);
}

std::istream& operator>>(std::istream& in, GameEngine& engine) {
    in >> engine.deck;
    int n;
    in >> n;
    engine.players.clear();
    for (int i = 0; i < n; i++) {
        Player p;
        in >> p;
        engine.addPlayer(p);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const GameEngine& engine) {
    out << "Deck: " << engine.deck << std::endl;
    for (auto& p : engine.players)
        out << p << std::endl;
    return out;
}
