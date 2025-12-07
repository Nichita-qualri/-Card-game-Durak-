#include "../Game.h" 
#include <cassert>
#include <iostream>

void testInit() {
    Game game;
    game.init(2); // Inițializăm jocul cu 2 jucători
    // Presupunem că jocul nu s-a terminat imediat după init
    assert(!game.isGameOver());
    std::cout << "TestInit passed\n";
}

void testAddPlayer() {
    Game game;
    game.init(1); // Pornim cu un jucător
    game.addPlayer("Player2"); // Adăugăm un alt jucător
    // Verificăm că acum sunt 2 jucători
    assert(game.getPlayerCount() == 2);
    std::cout << "TestAddPlayer passed\n";
}

void testGameOver() {
    Game game;
    game.init(2);
    // Aici putem simula sfârșitul jocului
    game.endGame(); // Folosim metoda endGame dacă există
    assert(game.isGameOver());
    std::cout << "TestGameOver passed\n";
}

int main() {
    testInit();
    testAddPlayer();
    testGameOver();
    std::cout << "All tests finished.\n";
    return 0;
}
