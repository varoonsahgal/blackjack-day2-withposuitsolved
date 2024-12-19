#ifndef GAME_HPP
#define GAME_HPP

#include "deck.hpp"
#include "dealer.hpp"
#include "player.hpp"
#include "print.hpp"
#include "statistics.hpp"
#include <string>

class Game{

    private:
        Player player;   // Player in the game (user)
        Dealer dealer;   // Dealer in the game
        Deck deck;       // Deck of cards in the game
        Statistics s;    // Leaderboard

    public:
        Game();

        // Core game logic
        bool dealDealer();
        char compareSum();
        bool checkWins();
        char checkEnd();
        char test(bool &retFlag);

        // Betting and actions
        bool startBet();
        bool startGame();
        bool processPlayerActions();
        void dealInitialCards();
        bool checkImmediateWin();
        bool handleBets();

        // Game state management
        void initializeGameState();

        // Game flow and rounds
        void beginGame();
        void finalizeRound();
        void saveGamePrompt();

        // Menu handling
        void beginMenu(bool rep, std::string message);
        void handleStartNewGame();
        void handleLoadGame();
        void handleViewStatistics();
        void handleViewInstructions();

        // File handling
        void saveGame();
        void loadGame();
        std::string promptForFilename();
        bool validateFileExistence(const std::string& path);
        void writeBinaryData(const std::string& path);

        // Printing
        void printStatistics();
        void printInstructions();
        void printTop();
        void printBody();
};

#endif