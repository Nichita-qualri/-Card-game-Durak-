#include "../Score.h"
#include <cassert>
#include <iostream>

void testScoreInit() {
    Score s;
    assert(s.getPoints() == 0); // Presupunem că inițial punctele sunt 0
    std::cout << "✅ testScoreInit passed\n";
}

void testAddPoints() {
    Score s;
    s.addPoints(5);
    assert(s.getPoints() == 5);
    std::cout << "✅ testAddPoints passed\n";
}

int main() {
    testScoreInit();
    testAddPoints();
    std::cout << "All Score tests finished.\n";
    return 0;
}
