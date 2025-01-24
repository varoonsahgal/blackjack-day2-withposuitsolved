#include "headers/human.hpp"
#include <iostream>

// Default Constructor
Human::Human(){
}

// Getter Function for sum to check end of game
int Human::getSum(){
    //Human does have a hand object called hand
    //and that hand object has functions that can be called

	return hand.getTotalValue();

}

// Switches Ace between 1 and 11
//void Human::switchAce(){
//    if(sum>21){
//        for(int i=0;i<hand.size();i++){
//                if(hand[i].getNumber()==1 && !(hand[i].getBlock())){
//                    hand[i].setBlock(true);
//                    sum-=10;
//                    return;
//                }
//        }
//    }
//}

// Adds card to Human's hand
void Human::addCard(Card c){
	hand.addCard(c);
}

// Clears Human's hand
void Human::clearCards(){
    hand.clear();
}

// Prints Human's cards

//want to move print cards to hand class
//why would i want to make the function static before i move it?
//because it does not depend on the object 
//and it makes it EASIER to move the function when it is static
//AND NOT break things!!
void Human::printCards(){
	hand.print();
}