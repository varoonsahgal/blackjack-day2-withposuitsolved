#ifndef SUIT_HPP
#define SUIT_HPP

#include <string>
#include <vector>


enum class Suit
{
	Hearts,
	Diamonds,
	Clubs,
	Spades,
    Invalid
};

inline std::vector<Suit> getAllSuits() {
    return { Suit::Spades,Suit::Hearts, Suit::Diamonds, Suit::Clubs };
}


// Free function to convert Suit to a string
inline std::string toString(Suit suit) {
    switch (suit) {
    case Suit::Hearts: return "Hearts";
    case Suit::Diamonds: return "Diamonds";
    case Suit::Clubs: return "Clubs";
    case Suit::Spades: return "Spades";
    default: return "Unknown";
    }
}

#endif // SUIT_HPP
