# Fixing Long functions in Game class.

For as much time as you have in this lab, apply the Clarification Refactoring to the Game class (only). This means using the Extract Function automated refactoring on any methods that have the Long Method/Function code smell.

Your goal is to extract functions for meaning to make the overall code easier to read and understand at a glance.


## 1. **Long Methods**
### Observations:
- **`Game::beginGame`**:
  - This method contains a complex game loop interspersed with calls to multiple functionalities like checking bets, dealing cards, comparing sums, and handling results.
  - It spans multiple concerns, making it hard to test and understand.
- **`Game::startBet`**:
  - Contains nested loops and switches, mixing logic for user input and player state management.
- **`Game::saveGame` and `Game::loadGame`**:
  - Both methods include large chunks of file handling logic with no abstraction for repeated operations like reading/writing player data.
