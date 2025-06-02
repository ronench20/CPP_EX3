//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GOVERNOR_HPP
#define CPP_EX3_GOVERNOR_HPP

#include "../GameRules.hpp"

namespace player{

    class Governor : public GameRules{
    public:
        /**
         * Constructs a Governor with the given name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        Governor(const std::string& name, BoardGame* boardGame);

        /**
         * Performs the tax action for the Governor.
         * Overrides the base class implementation.
         */
        void tax() override;

        /**
         * Blocks a tax action targeting the specified player.
         * @param target The player whose tax action is being blocked.
         */
        void taxBlock(Player& target);
    };
}

#endif //CPP_EX3_GOVERNOR_HPP