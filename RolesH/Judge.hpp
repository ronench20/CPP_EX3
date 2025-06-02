//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_JUDGE_HPP
#define CPP_EX3_JUDGE_HPP

#include "../GameRules.hpp"

namespace player{

    class Judge : public GameRules{
    public:
        /**
         * Constructs a Judge with the given name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        Judge(const std::string& name, BoardGame* boardGame);

        /**
         * Blocks a bribe action targeting the specified player.
         * @param target The player whose bribe is being blocked.
         */
        void blockBribe(Player& target);
    };
}

#endif //CPP_EX3_JUDGE_HPP