#include "../Game.h"
#include <cassert>
#include <iostream>

void testInit() {
    Game game;
    game.init(2); // Inițializare joc cu 2 jucători
    // Presupunem că jocul nu e gata imediat după init
    assert(!game.isGameOver());
    std::cout << "✅ testInit passed\n";
}

void testAddPlayer() {
    Game game;
    game.init(1);
    game.addPlayer("Player2"); // Adăugăm al doilea jucător
    assert(game.getPlayerCount() == 2);
    std::cout << "✅ testAddPlayer passed\n";
}

void testGameOver() {
    Game game;
    game.init(2);
    game.endGame(); // Simulăm sfârșitul jocului
    assert(game.isGameOver());
    std::cout << "✅ testGameOver passed\n";
}

int main() {
    testInit();
    testAddPlayer();
    testGameOver();
    std::cout << "All tests finished.\n";
    return 0;
}
