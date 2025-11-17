#include <iostream>
#include <memory>
#include "GameEngine.hpp"
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "painter.hpp"

int main() {
    GameEngine engine;

    engine.addPlayer(std::make_shared<Player>("Alice"));
    engine.addPlayer(std::make_shared<Player>("Bob"));

    engine.run();

    Painter painter;
    Point topLeft(0, 0);
    Point bottomRight(5, 5);
    char* image[1] = { nullptr };
    painter.DrawImage(topLeft, bottomRight, image);
    painter.WriteText(Point(1, 1), "Welcome to the game!");

    std::cout << std::endl << "Players info via operator<<:" << std::endl;
    for (auto& player : { std::make_shared<Player>("Alice"), std::make_shared<Player>("Bob") }) {
        std::cout << *player << std::endl;
    }

    return 0;
}