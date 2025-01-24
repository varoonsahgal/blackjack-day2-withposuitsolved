#ifndef CONSOLE_CARD_H
#define CONSOLE_CARD_H

#include "card.h"
#include <iostream>

class ConsoleCard {
public:
    // Prints the first line of a card based on its suit
    void printCardL1(Card card);

    // Prints the second line of a card based on its suit
    void printCardL2( Card card);

    // Returns a printable character representing the card's number
    char getPrintNumber( Card card);
};

#endif
