#include <iostream>
#include <memory>
#include <windows.h> 
#include "game_engine.hpp"
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "painter.hpp" 

int main() {
    SetConsoleCP(CP_UTF8);         
    SetConsoleOutputCP(CP_UTF8);   

    GameEngine engine;

    engine.addPlayer(std::make_shared<Player>("Alice"));
    engine.addPlayer(std::make_shared<Player>("Bob"));

    engine.run();


    std::cout << std::endl << "Players info via operator<<:" << std::endl;
    for (auto& player : { std::make_shared<Player>("Alice"), std::make_shared<Player>("Bob") }) {
        std::cout << *player << std::endl;
    }

    return 0;
}