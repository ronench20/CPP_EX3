//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GAMERULES_HPP
#define CPP_EX3_GAMERULES_HPP

#include "Player.hpp"
#include "BoardGame.hpp"
#include <string>

namespace player{

    class BoardGame;

    class GameRules : public Player{
    protected:
        BoardGame* boardGame;
        bool bribeBlocked = false;
    public:
        /**
         * Constructs a GameRules object with a name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        GameRules(const std::string& name, BoardGame* boardGame);

        /**
         * Performs the gather action for the player.
         */
        void gather();

        /**
         * Performs the tax action for the player.
         * Can be overridden by derived classes.
         */
        virtual void tax();

        /**
         * Performs the bribe action for the player.
         */
        void bribe();

        /**
         * Arrests the target player.
         * @param target The player to arrest.
         */
        virtual void arrest(Player& target);

        /**
         * Sanctions the target player.
         * @param target The player to sanction.
         */
        virtual void sanction(Player& target);

        /**
         * Performs a coup on the target player.
         * @param target The player to coup.
         */
        virtual void coup(Player& target);

        /**
         * resets the turn.
         */
        void startTurn();

        /**
         * Checks if the player must perform a coup.
         * @return True if a coup is mandatory, false otherwise.
         */
        bool mustCoup() const;

        /**
         * Skips the player's turn.
         */
        void skipTurn();

        /**
         * Gets the bribe blocked status.
         * @return True if bribe is blocked, false otherwise.
         */
        bool getBribeBlocked() const;

        /**
         * Sets the bribe blocked status.
         * @param value True to block bribe, false to allow.
         */
        void setBribeBlocked(bool value);

    };
}

#endif //CPP_EX3_GAMERULES_HPP