//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_SPY_HPP
#define CPP_EX3_SPY_HPP

#include "../GameRules.hpp"

namespace player{

    class Spy : public GameRules{
    private:
        bool spiedThisTurn = false;
    public:
        /**
         * Constructs a Spy with the given name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        Spy(const std::string& name, BoardGame* boardGame);

        /**
         * Gets the number of coins another player has.
         * @param other The player whose coins to view.
         * @return The number of coins the other player has.
         */
        int getCoins(Player &other) const;

        /**
         * Blocks the arrest action on the target player.
         * @param target The player whose arrest is being blocked.
         */
        void arrestBlock(Player &target);

        /**
         * Resets the spiedThisTurn flag to false.
         */
        void resetSpiedThisTurn();

        /**
         * Checks if the spy action was used this turn.
         * @return True if the spy action was used, false otherwise.
         */
        bool getSpiedThisTurn() const;
    };
}

#endif //CPP_EX3_SPY_HPP