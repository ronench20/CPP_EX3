//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GOVERNOR_HPP
#define CPP_EX3_GOVERNOR_HPP

#include "GameRules.hpp"

namespace player{
    class Governor : public GameRules{
    public:
        Governor(const std::string& name, BoardGame* boardGame);
        void tax() override;
        void taxBlock(Player& target);
    };
}

#endif //CPP_EX3_GOVERNOR_HPP
