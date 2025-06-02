//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_MERCHANT_HPP
#define CPP_EX3_MERCHANT_HPP

#include "../GameRules.hpp"

namespace player{

    class Merchant : public GameRules{
    public:
        /**
         * Constructs a Merchant with the given name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        Merchant(const std::string& name, BoardGame* boardGame);

        /**
         * Called at the start of the Merchant's turn to give him extra coin.
         */
        void startTurn() override;

        /**
         * Gives the Merchant an extra coin.
         */
        void extraCoin();
    };
}

#endif //CPP_EX3_MERCHANT_HPP