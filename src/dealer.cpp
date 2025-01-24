#include "headers/dealer.hpp"
#include <iostream>
#include "headers/consolecard.hpp"


// Prints first card revealed and second card hidden
void Dealer::printFirstCard() {
    ConsoleCard consoleCard;
    std::cout << "\n";
    std::cout << ".------..------." << "\n";
    std::cout << "|" << consoleCard.getPrintNumber(hand[0]) << ".--. || .--. |" << "\n";
    consoleCard.printCardL1(hand[0]);
    std::cout << "|  //  |" << "\n";
    consoleCard.printCardL2(hand[0]);
    std::cout << "|  //  |" << "\n";
    std::cout << "| '--'" << consoleCard.getPrintNumber(hand[0]) << "|| '--' |" << "\n";
    std::cout << "`------'`------'" << "\n";
}
