#include "headers/hand.hpp"
#include "headers/card.h"
#include <iostream>

Hand::Hand() : totalValue(0) {}

void Hand::addCard(const Card& card) {
    cards.push_back(card);
    updateTotalValue();
}

void Hand::clear() {
    cards.clear();
    totalValue = 0;
}

int Hand::getTotalValue() const {
    return totalValue;
}

void Hand::updateTotalValue() {
    totalValue = 0;
    for (Card card : cards) {
        totalValue += (card.getNumber() > 10) ? 10 : card.getNumber();
        if (card.getNumber() == 1 && totalValue <= 11) {
            totalValue += 10;
        }
    }
}

void Hand::print() const {
    std::cout << "\n";
    for (int i = 0; i < 6; i++) {
        for (Card card : cards) {
            switch (i) {
            case 0: std::cout << ".------."; break;
            case 1: std::cout << "|" << card.getPrintNumber() << ".--. |"; break;
            case 2: card.printCardL1(); break;
            case 3: card.printCardL2(); break;
            case 4: std::cout << "| '--'" << card.getPrintNumber() << "|"; break;
            case 5: std::cout << "`------`";
            }
        }
        std::cout << "\n";
    }
}

const std::vector<Card>& Hand::getCards() const {
    return cards;
}
