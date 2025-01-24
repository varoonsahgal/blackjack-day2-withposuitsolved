#include "headers/consolecard.hpp"

void ConsoleCard::printCardL1(Card card) {
    switch (card.getSuit()) {
    case Suit::Clubs:    std::cout << "| :(): |"; break;
    case Suit::Hearts:   std::cout << "| (\\/) |"; break;
    case Suit::Diamonds:
    case Suit::Spades:   std::cout << "| :/\\: |"; break;
    default:             std::cout << "|  //  |";
    }
}

void ConsoleCard::printCardL2(Card card) {
    switch (card.getSuit()) {
    case Suit::Clubs:    std::cout << "| ()() |"; break;
    case Suit::Hearts:
    case Suit::Diamonds: std::cout << "| :\\/: |"; break;
    case Suit::Spades:   std::cout << "| (__) |"; break;
    default:             std::cout << "|  //  |";
    }
}

char ConsoleCard::getPrintNumber(Card card) {
    switch (card.getNumber()) {
    case 1:  return 'A';
    case 10: return 'X';
    case 11: return 'J';
    case 12: return 'Q';
    case 13: return 'K';
    default: return '0' + card.getNumber();
    }
}
