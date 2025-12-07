#include "../Player.h"
#include <cassert>
#include <iostream>

void testPlayerCreation() {
    Player p("John");
    assert(p.getName() == "John");
    std::cout << "TestPlayerCreation passed\n";
}

void testPlayerScore() {
    Player p("Anna");
    p.addScore(10);
    assert(p.getScore() == 10);
    std::cout << "TestPlayerScore passed\n";
}

int main() {
    testPlayerCreation();
    testPlayerScore();
    std::cout << "All Player tests finished.\n";
    return 0;
}
