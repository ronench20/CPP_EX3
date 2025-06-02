//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_BARON_HPP
#define CPP_EX3_BARON_HPP

#include "../GameRules.hpp"

namespace player{

    class Baron : public GameRules{
    public:
        /**
         * Constructs a Baron with the given name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        Baron(const std::string& name, BoardGame* boardGame);

        /**
         * Performs the invest action for the Baron.
         */
        void invest();
    };
}

#endif //CPP_EX3_BARON_HPP