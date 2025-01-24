#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "card.h"
#include <vector>
#include "hand.hpp"

class Human{

    protected:
        Hand hand; //this NO LONGER suffers from PO

    public:
        Human();
        int getSum();
        //void switchAce();
        void addCard(Card c);
        void clearCards();
        void printCards();
};

#endif