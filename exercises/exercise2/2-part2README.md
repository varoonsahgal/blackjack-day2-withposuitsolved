In this part 2 of exercise 2, you will write some test cases on your own for practice.

Now, we will specifically write some tests for the Game class!

In your tests folder, create a new file `game_test.cpp` and write the code there.

There are hints to help you write out tests.

Also note that you will need to modify the Makefile in order to run these tests - namely, you will need to modify this portion to factor in the updated game_test file:

```
TEST_SRC_FILES = $(SRC_DIR)/card.cpp $(SRC_DIR)/compatible.cpp \
                $(SRC_DIR)/dealer.cpp $(SRC_DIR)/deck.cpp $(SRC_DIR)/game.cpp \
                $(SRC_DIR)/human.cpp $(SRC_DIR)/player.cpp $(SRC_DIR)/print.cpp $(SRC_DIR)/statistics.cpp \
                $(TEST_DIR)/card_test.cpp $(TEST_DIR)/game_test.cpp

```


---

# Let's write some tests!


### **1. Test: Initialization of the `Game` Object** 🛠️
**Test Name**:
```cpp
TEST(GameTest, InitializesCorrectly) {
    // Hint: Think about what happens when a Game object is constructed.
    // Verify attributes like:
    // - Is the deck properly initialized?
    // - Are the player and dealer objects created and in the expected state?
    // - Are there any edge cases related to initialization you need to handle?
}
```

---

### **2. Test: Starting the Game** 🃏
**Test Name**:
```cpp
TEST(GameTest, DealsInitialCardsProperly) {
    // Hint: Focus on the `startGame` or equivalent method.
    // - Does the player and dealer receive the correct number of cards?
    // - What happens if the deck has fewer cards than needed to start a game?
    // - Are cards removed from the deck after being dealt?

    //  most importantly - are these things even testable right now??
}
```

---

### **3. Test: Placing Bets** 💵
**Test Name**:
```cpp
TEST(GameTest, HandlesBetPlacement) {
    // Hint: Think about the conditions for placing a bet.
    // - Is the player's cash deducted correctly?
    // - What happens if the player tries to bet more cash than they have?
    // - Does the game correctly handle edge cases like a player with zero cash?

    //  most importantly - are these things even testable right now??

}
```

---

### **4. Test: Dealer's Turn Logic** 🎲
**Test Name**:
```cpp
TEST(GameTest, DealerFollowsHitUntilSeventeenRule) {
    //Question: is it even possible to test these things?


    // Hint: The dealer's turn follows specific rules.
    // - Verify that the dealer continues hitting until their sum reaches or exceeds 17.
    // - Check that the dealer stops hitting at the correct point.
    // - Handle edge cases, like when the dealer's initial hand already meets or exceeds 17.
}
```

---

### **5. Test: Game Outcome Determination** 🏆
**Test Name**:
```cpp
TEST(GameTest, DeterminesWinnerCorrectly) {
    //Question: is it even possible to test these things?

    // Hint: Focus on how the game determines winners and losers.
    // - Test scenarios like:
    //   - Player wins with a higher score.
    //   - Dealer wins with a higher score.
    //   - A draw when both scores are equal.
    //   - Player wins with a blackjack.
    //   - Both the dealer and player bust.
}
```

---

