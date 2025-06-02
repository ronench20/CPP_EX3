//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_BOARDGAME_HPP
#define CPP_EX3_BOARDGAME_HPP

#include <iostream>
#include "Player.hpp"

namespace player{


    class BoardGame{
    private:
        Player *playersList[6];
        int numOfPlayers = 0;
        int currentPlayerIndex = 0;

        int generals[6];
        bool awaitingCoup = false;
        int attackerIndex = -1;
        int targetIndex = -1;
        int numOfGenerals = 0;
        int nextGeneralIndex = 0;

        int judges[6];
        bool awaitingBribe = false;
        int briberIndex = -1;
        int targetJudgeIndex = -1;
        int numOfJudges = 0;
        int nextJudgeIndex = 0;

    public:
        /**
         * Constructs a new BoardGame instance.
         */
        BoardGame();

        /**
         * Destroys the BoardGame instance and cleans up resources.
         */
        ~BoardGame();

        /**
         * Adds a player to the game.
         * @param player Pointer to the player to add.
         */
        void addPlayer(Player* player);

        /**
         * Gets the name of the player whose turn it is.
         * @return The current player's name.
         */
        std::string turn();

        /**
         * Gets a pointer to the current player.
         * @return Pointer to the current player.
         */
        Player* getCurrentPlayer() const;

        /**
         * Gets the number of players in the game.
         * @return The number of players.
         */
        int getNumOfPlayers() const;

        /**
         * Gets a pointer to the player at the specified index.
         * @param index The index of the player.
         * @return Pointer to the player at the given index.
         */
        Player* getPlayerIndex(int index) const;

        /**
         * Gets the index of the current player.
         * @return The current player's index.
         */
        int getCurrentPlayerIndex() const;

        /**
         * Gets a string listing all players in the game.
         * @return A string of player names.
         */
        std::string players() const;

        /**
         * Gets the name of the winning player, if there is one.
         * @return The winner's name.
         */
        std::string winner() const;

        /**
         * Ends the game and performs any necessary cleanup.
         */
        void endGame();

        /**
         * Checks if the game has a winner.
         * @return True if there is a winner, false otherwise.
         */
        bool hasWinner() const;

        /**
         * Advances the game to the next player's turn.
         */
        void nextTurn();

        /**
         * Creates and adds a new player with the given name.
         * @param name The name of the new player.
         */
        void createPlayer(const std::string& name);

        /**
         * Removes the player at the specified index from the game.
         * @param index The index of the player to remove.
         */
        void removePlayer(int index);

        /**
         * Checks if a coup is currently awaiting approval.
         * @return True if awaiting coup approval, false otherwise.
         */
        bool getAwaitingCoup() const;

        /**
         * Gets the index of the current general involved in a coup.
         * @return The current general's index.
         */
        int getCurrGeneralIndex() const;

        /**
         * Checks if a general can prevent a coup.
         * @return True if a general can prevent the coup, false otherwise.
         */
        bool canGeneralPreventCoup() const;

        /**
         * Initiates coup approval process for the given attacker and target.
         * @param attackerIndex Index of the attacking player.
         * @param targetIndex Index of the target player.
         */
        void coupApproval(int attackerIndex, int targetIndex);

        /**
         * Resolves the coup decision.
         * @param prevent True if the coup is prevented, false otherwise.
         */
        void coupDecision(bool prevent);

        /**
         * Clears the coup approval state.
         */
        void clearApproval();

        /**
         * Checks if a bribe is currently awaiting approval.
         * @return True if awaiting bribe approval, false otherwise.
         */
        bool getAwaitingBribe() const;

        /**
         * Gets the index of the current judge involved in a bribe.
         * @return The current judge's index.
         */
        int getCurrJudgeIndex() const;

        /**
         * Initiates bribe approval process for the given briber.
         * @param briberIndex Index of the player offering the bribe.
         */
        void bribeApproval(int briberIndex);

        /**
         * Resolves the bribe decision.
         * @param prevent True if the bribe is prevented, false otherwise.
         */
        void bribeDecision(bool prevent);

        /**
         * Clears the bribe approval state.
         */
        void clearBribeApproval();
    };
}

#endif //CPP_EX3_BOARDGAME_HPP