#ifndef CARD_H
#define CARD_H
#include "suit.hpp"


class Card{
    
    private:
        int number; // Card Number
        Suit suit;  // Card Suit
        bool block; // Boolean value for Ace Switching

    public:
        // Default Constructor
        Card();
        // Parameterised Constructor (for initializing deck)
       // Card(int no, char s);
        Card(int no, Suit suit);

        // Getter Functions    
        int getNumber();
        Suit getSuit();
        bool getBlock();
        // Setter Functions
        void setNumber(int no);
        void setSuit(Suit s);
        void setBlock(bool b);
        // Printing Card Details
        char getPrintNumber();
        void printCardL1();
        void printCardL2();
        
        Suit charToSuit(char c);
};

#endif