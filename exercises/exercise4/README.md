Our Deck class suffers from primitive obsession:

```
void Deck::initializeDeck(){
    deck.clear();
    char suits[4] = {'S','H','D','C'};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            Card c(j+1,suits[i]);
            deck.push_back(c);
        }
    }
```

# Three Rules of Primitive Obsession¶


- It's an Unconstrained Type (not local variable)
- It's used in Logic/Comparisons, Calculations, or a Loop
- It is not the sole concern of the class that it's in

Refactor suits to use an enum instead
