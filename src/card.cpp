#include "headers/card.h"
#include <iostream>
#include "headers/suit.hpp"

// Default Constructor
Card::Card(){
    number = 0;
    suit = Suit::Hearts; //some default value
    block = false;
}

// Parameterised Constructor (for initializing deck)
// original constructor
// 
//Card::Card(int no, char s) : Card(no, charToSuit(s)) {}

//Card::Card(int no, char s) {
//	number = no;
//	suit = charToSuit(s);
//	block = false;
//}


// new constructor that we want to work towards
Card::Card(int no, Suit suit) : number(no), suit(suit), block(false) {}


int Card::getNumber(){
    return number;
}

Suit Card::getSuit(){
    return suit;
}  
bool Card::getBlock(){
    return block;
}

void Card::setNumber(int no){
    number = no;
}
void Card::setSuit(Suit c){
    suit = c;
}
void Card::setBlock(bool b){
    block = b;
}

char Card::getPrintNumber(){
    switch(number){
        case 1: return 'A';
        case 10: return 'X';
        case 11: return 'J';
        case 12: return 'Q';
        case 13: return 'K';
        default: char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
                    return digits[number];
    }
}
void Card::printCardL2(){
    switch(suit){
    case Suit::Clubs: std::cout<<"| ()() |"; break;
    case Suit::Hearts:
    case Suit::Diamonds: std::cout<<"| :\\/: |"; break;
    case Suit::Spades: std::cout<<"| (__) |"; break;
        default : std::cout<<"|  //  |";
    }
}

void Card::printCardL1() {
    switch(suit) {
    case Suit::Clubs: std::cout << "| :(): |"; break;
    case Suit::Hearts: std::cout << "| (\\/) |"; break;
    case Suit::Diamonds:
    case Suit::Spades: std::cout << "| :/\\: |"; break;
    default: std::cout << "|  //  |";
    }
}

//this is scaffolding and we no longer need it!
Suit Card::charToSuit(char c) {
    switch (c) {
    case 'H': return Suit::Hearts;
    case 'D': return Suit::Diamonds;
    case 'C': return Suit::Clubs;
    case 'S': return Suit::Spades;
    default: return Suit::Invalid;
    }
}
