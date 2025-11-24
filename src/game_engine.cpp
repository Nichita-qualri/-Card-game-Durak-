#include "game_engine.hpp"
#include <iostream>
#include <algorithm>
#include <limits>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const WORD WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
const WORD BRIGHT_WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
const WORD TRUMP_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD CYAN_BLACK_SUIT = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

void setSuitColor(Suit suit) {
    switch (suit) {
    case Suit::Spades:
    case Suit::Clubs:
        SetConsoleTextAttribute(hConsole, CYAN_BLACK_SUIT);
        break;
    case Suit::Hearts:
    case Suit::Diamonds:
        SetConsoleTextAttribute(hConsole, RED);
        break;
    }
}

void setNormalColor() {
    SetConsoleTextAttribute(hConsole, BRIGHT_WHITE);
}

void setCardColor(CardPtr card, Suit trump) {
    if (card->getSuit() == trump) {
        SetConsoleTextAttribute(hConsole, TRUMP_YELLOW);
    }
    else {
        setSuitColor(card->getSuit());
    }
}

GameEngine::GameEngine() {
    for (int s = 0; s < 4; ++s) {
        for (int r = 0; r < 9; ++r) {
            deck.addCard(std::make_shared<Card>(
                static_cast<Suit>(s),
                static_cast<Rank>(r),
                false
            ));
        }
    }
}

void GameEngine::addPlayer(PlayerPtr player) {
    players.push_back(player);
}

bool GameEngine::canBeat(CardPtr defense, CardPtr attack, Suit trump) {
    if (defense->getSuit() == trump && attack->getSuit() != trump) {
        return true;
    }

    if (defense->getSuit() == attack->getSuit()) {
        return defense->getRank() > attack->getRank();
    }

    return false;
}

int GameEngine::getPlayerChoice(PlayerPtr player, bool allowTake) {
    if (player->handSize() == 0) return -1;

    int choice;
    while (true) {
        setNormalColor();
        if (allowTake) {
            std::cout << "Choose card (0-" << player->handSize() - 1
                << ") or -1 to take: ";
        }
        else {
            std::cout << "Choose card (0-" << player->handSize() - 1 << "): ";
        }

        if (!(std::cin >> choice)) {
            SetConsoleTextAttribute(hConsole, RED);
            std::cout << "Input error! Please enter a number." << std::endl;
            setNormalColor();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (allowTake && choice == -1) return -1;
        if (choice >= 0 && choice < player->handSize()) return choice;

        SetConsoleTextAttribute(hConsole, TRUMP_YELLOW);
        std::cout << "Invalid choice! Try again. Current hand: ";
        player->showHand();
        setNormalColor();
    }
}

void displayPlayerHand(PlayerPtr player, Suit trump) {
    setNormalColor();
    std::cout << player->getName() << "'s hand: ";
    const auto& hand = player->getHand();
    for (size_t i = 0; i < hand.size(); ++i) {
        CardPtr card = hand[i];

        setCardColor(card, trump);

        std::cout << "[" << i << "]" << card->shortString() << " ";

        setNormalColor();
    }
    std::cout << std::endl;
}

void GameEngine::run() {
    if (players.size() != 2) {
        std::cout << "Need exactly 2 players!" << std::endl;
        return;
    }

    deck.shuffle();
    deck.setTrumpSuit();
    Suit trump = deck.getTrumpSuit();

    SetConsoleTextAttribute(hConsole, MAGENTA);
    std::cout << "\n=== DURAK GAME ===" << std::endl;

    setNormalColor();
    std::cout << "Trump suit: ";

    SetConsoleTextAttribute(hConsole, TRUMP_YELLOW);
    std::cout << SuitHelper::ToString(trump) << " "
        << SuitHelper::ToSymbol(trump) << std::endl << std::endl;
    setNormalColor();

    auto dealCardToPlayer = [&](PlayerPtr p) {
        CardPtr card = deck.dealCard();
        if (card) {
            if (card->getSuit() == trump) {
                card = std::make_shared<Card>(
                    card->getSuit(),
                    card->getRank(),
                    true
                );
            }
            p->addCard(card);
        }
        };

    for (int i = 0; i < 6; ++i) {
        for (auto& player : players) {
            dealCardToPlayer(player);
        }
    }

    int attackerIndex = 0;

    while (true) {
        PlayerPtr attacker = players[attackerIndex];
        PlayerPtr defender = players[1 - attackerIndex];

        SetConsoleTextAttribute(hConsole, CYAN);
        std::cout << "\n--- New Round ---" << std::endl;

        SetConsoleTextAttribute(hConsole, GREEN);
        std::cout << "Attacker: " << attacker->getName() << std::endl;

        SetConsoleTextAttribute(hConsole, BLUE);
        std::cout << "Defender: " << defender->getName() << std::endl;

        setNormalColor();
        std::cout << "Cards in deck: " << deck.size() << std::endl;

        displayPlayerHand(attacker, trump);
        displayPlayerHand(defender, trump);
        std::cout << std::endl;

        setNormalColor();
        std::cout << attacker->getName() << ", choose a card to attack with." << std::endl;
        int attackChoice = getPlayerChoice(attacker);

        if (attackChoice == -1) {
            SetConsoleTextAttribute(hConsole, TRUMP_YELLOW);
            std::cout << attacker->getName() << " has no cards left to attack! Round skip." << std::endl;
            setNormalColor();
            attackerIndex = 1 - attackerIndex;
            continue;
        }

        CardPtr attackCard = attacker->getHand()[attackChoice];
        SetConsoleTextAttribute(hConsole, GREEN);
        std::cout << attacker->getName() << " attacks with: ";

        setCardColor(attackCard, trump);
        std::cout << attackCard->shortString() << std::endl;
        setNormalColor();

        std::cout << defender->getName() << ", choose a card to defend with (or -1 to take)." << std::endl;
        int defenseChoice = getPlayerChoice(defender, true);

        std::vector<CardPtr> playedCards = { attackCard };

        if (defenseChoice == -1) {
            SetConsoleTextAttribute(hConsole, RED);
            std::cout << defender->getName() << " takes the cards!" << std::endl;
            setNormalColor();
            for (auto& card : playedCards) {
                defender->addCard(card);
            }
            attacker->removeCard(attackChoice);
        }
        else {
            CardPtr defenseCard = defender->getHand()[defenseChoice];

            if (canBeat(defenseCard, attackCard, trump)) {
                SetConsoleTextAttribute(hConsole, BLUE);
                std::cout << defender->getName() << " defends with: ";
                setCardColor(defenseCard, trump);
                std::cout << defenseCard->shortString() << std::endl;

                SetConsoleTextAttribute(hConsole, GREEN);
                std::cout << "Defense successful! Cards are discarded." << std::endl;
                setNormalColor();

                attacker->removeCard(attackChoice);
                defender->removeCard(defenseChoice);

                attackerIndex = 1 - attackerIndex;
            }
            else {
                SetConsoleTextAttribute(hConsole, RED);
                std::cout << "Card ";

                setCardColor(defenseCard, trump);
                std::cout << defenseCard->shortString();

                SetConsoleTextAttribute(hConsole, RED);
                std::cout << " doesn't beat ";

                setCardColor(attackCard, trump);
                std::cout << attackCard->shortString();

                SetConsoleTextAttribute(hConsole, RED);
                std::cout << "!" << std::endl;

                std::cout << defender->getName() << " takes the cards!" << std::endl;
                setNormalColor();

                defender->addCard(attackCard);
                defender->addCard(defenseCard);
                attacker->removeCard(attackChoice);
                defender->removeCard(defenseChoice);
            }
        }

        setNormalColor();
        std::cout << "Dealing cards from deck..." << std::endl;

        while (attacker->handSize() < 6 && !deck.isEmpty()) {
            dealCardToPlayer(attacker);
        }

        while (defender->handSize() < 6 && !deck.isEmpty()) {
            dealCardToPlayer(defender);
        }

        if (deck.isEmpty()) {
            SetConsoleTextAttribute(hConsole, MAGENTA);
            std::cout << "\n=== FINAL ROUND (Deck is empty) ===" << std::endl;
            setNormalColor();

            if (attacker->handSize() == 0 && defender->handSize() > 0) {
                SetConsoleTextAttribute(hConsole, GREEN);
                std::cout << "\n=== GAME OVER ===" << std::endl;
                std::cout << attacker->getName() << " wins!" << std::endl;
                SetConsoleTextAttribute(hConsole, RED);
                std::cout << defender->getName() << " is the DURAK (fool)!" << std::endl;
                setNormalColor();
                break;
            }
            if (defender->handSize() == 0 && attacker->handSize() > 0) {
                SetConsoleTextAttribute(hConsole, GREEN);
                std::cout << "\n=== GAME OVER ===" << std::endl;
                std::cout << defender->getName() << " wins!" << std::endl;
                SetConsoleTextAttribute(hConsole, RED);
                std::cout << attacker->getName() << " is the DURAK (fool)!" << std::endl;
                setNormalColor();
                break;
            }
            if (attacker->handSize() == 0 && defender->handSize() == 0) {
                SetConsoleTextAttribute(hConsole, CYAN);
                std::cout << "\n=== GAME OVER ===" << std::endl;
                std::cout << "Draw! No Durak in this case." << std::endl;
                setNormalColor();
                break;
            }
        }
    }
}