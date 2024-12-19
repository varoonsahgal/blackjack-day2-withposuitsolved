In the last exercise we saw how difficult it was to write any good tests for the Game class.

This is because it's trying to do too many things.

So, we are stuck in a loop of "I'm afraid to change my code because i dont have good tests..." but the reason you don't have any good tests is because the code is fundamentally not "clean".


The **Single Responsibility Principle (SRP)** (the "S" in SOLID) states that a class should have one and only one reason to change, meaning it should encapsulate only one responsibility. 

---

### **1. Mixed Responsibilities**
The `Game` class seems to handle multiple responsibilities, including:
- **Game Flow Management**: Starting and managing the game loop.
- **Player Interaction**: Handling player input (e.g., bets) and possibly validating it.
- **Game Logic**: Processing rules for betting, dealing cards, determining winners, etc.
- **State Management**: Maintaining the state of the game, such as tracking scores, wins/losses, and player statistics.
- **Rendering/UI**: Displaying menus, instructions, or statistics (e.g., via `printTop()`, `printStatistics()`).

Each of these is a separate concern, and bundling them into one class makes the `Game` class responsible for too many aspects of the application. This coupling violates SRP.

---

### **2. Example Violations in the Test Context**
The behavior observed in the test (`HandlesBetsCorrectly`) suggests that:
- Instantiating the `Game` class triggers unintended side effects, such as starting parts of the game.
- The `handleBets()` method not only validates bets but might also interact with unrelated components (e.g., game state transitions, UI logic, or player actions).

These responsibilities should be decoupled so that:
- The `Game` class focuses on orchestrating the overall game.
- Supporting classes handle specific concerns (e.g., `Player`, `Dealer`, `UI`, `GameState`).

---

### **How It Violates SRP**
Here’s a breakdown of how the `Game` class might be violating SRP based on the symptoms described:

| **Responsibility**                  | **Problem**                                                                                     | **Better Solution**                                                                                                       |
|-------------------------------------|-------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------|
| **Game Flow Management**            | The `Game` class likely handles starting and running the entire game.                          | Create a `GameController` or `GameEngine` class to handle high-level flow management.                                     |
| **Player Interaction**              | Player interactions like placing bets or taking actions may be handled directly by `Game`.     | Delegate to a `Player` or `PlayerInteraction` class for these interactions.                                               |
| **State Management**                | Tracking wins/losses, scores, or bets may be embedded in the `Game` class.                     | Use a separate `GameState` class to encapsulate state information.                                                        |
| **Game Logic**                      | Logic for betting, dealing, and rules is likely mixed with other responsibilities.             | Extract a `GameRules` or `GameLogic` class to handle these rules independently.                                           |
| **Rendering/UI**                    | Functions like `printStatistics()` or `printTop()` suggest the `Game` class directly handles UI. | Use a `GameRenderer`, `ConsoleUI`, or similar class to separate the rendering logic from the core game logic.              |

---

### **Refactoring for SRP**

#### **Proposed Architecture**
Refactor the `Game` class into smaller, focused classes, each with a single responsibility:

1. **Game (High-Level Orchestrator):**
   - Manages the high-level game flow and interacts with other components (e.g., `GameState`, `GameLogic`).
   ```cpp
   class Game {
   public:
       Game(GameState& state, GameLogic& logic, UI& ui);
       void startGame();
   private:
       GameState& gameState;
       GameLogic& gameLogic;
       UI& userInterface;
   };
   ```

2. **GameState:**
   - Tracks the state of the game (e.g., scores, player statistics).
   ```cpp
   class GameState {
   public:
       void resetState();
       void updateState();
   private:
       int currentRound;
       Player player;
       Dealer dealer;
   };
   ```

3. **GameLogic:**
   - Encapsulates the rules and logic of the game, such as handling bets, dealing cards, and determining winners.
   ```cpp
   class GameLogic {
   public:
       bool handleBets(Player& player);
       void dealCards();
       bool checkWinner();
   };
   ```

4. **UI (Rendering Layer):**
   - Handles all output and user interaction.
   ```cpp
   class UI {
   public:
       void printStatistics(const GameState& state);
       void printInstructions();
       std::string getInput();
   };
   ```

5. **PlayerInteraction:**
   - Handles actions specific to the player, such as placing bets or making moves.

---

### **Advantages of Refactoring**
1. **Better Testability**: 
   - Isolated responsibilities make it easier to test individual components (e.g., `GameLogic` or `GameState`) without starting the whole game.

2. **Improved Maintainability**:
   - Changes to one part of the application (e.g., rules, UI) do not affect unrelated parts.

3. **Reusability**:
   - Components like `GameLogic` or `UI` can be reused in other contexts (e.g., different games or interfaces).

4. **SRP Compliance**:
   - Each class has a clear and focused responsibility, making the system more robust and extensible.

---

### **What to Refactor in the Current `Game` Class**

Divide and conquer - start small by creating a new GameState class first, then move on to creating a GameLogic class, and so on...