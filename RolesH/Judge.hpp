//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_JUDGE_HPP
#define CPP_EX3_JUDGE_HPP

#include "../GameRules.hpp"

namespace player{
    class Judge : public GameRules{
    public:
        Judge(const std::string& name, BoardGame* boardGame);
        void blockBribe(Player& target);
    };
}

#endif //CPP_EX3_JUDGE_HPP
