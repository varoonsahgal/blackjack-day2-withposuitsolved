#ifndef HAND_HPP
#define HAND_HPP

#include "card.h"
#include <vector>

class Hand {

private:
    std::vector<Card> cards; // Collection of cards in the hand
    int totalValue;          // Cached total value of the hand

    void updateTotalValue(); // Helper to recalculate the hand's value

public:
    Hand();
    void addCard(const Card& card);
    void clear();
    int getTotalValue() const;
    void print() const;
    const std::vector<Card>& getCards() const;
};

#endif
