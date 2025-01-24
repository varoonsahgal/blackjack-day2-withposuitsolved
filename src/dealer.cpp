#include "headers/dealer.hpp"
#include <iostream>
#include "headers/consolecard.hpp"
#include "headers/card.h"

void Dealer::printFirstCard() {
    if (!hand.getCards().empty()) {
        //hand.front
		Card firstCard = hand.getCards().front();
        std::cout << ".------." << std::endl;
        std::cout << "|" << firstCard.getPrintNumber() << ".--. |" << std::endl;
        firstCard.printCardL1();
        std::cout << std::endl;
        firstCard.printCardL2();
        std::cout << std::endl;
        std::cout << "| '--'" << firstCard.getPrintNumber() << "|";
        std::cout << std::endl << "`------`" << std::endl;
    }
}
