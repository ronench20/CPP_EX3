//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GENERAL_HPP
#define CPP_EX3_GENERAL_HPP

#include "../GameRules.hpp"

namespace player{
    class General : public GameRules{
    public:
        General(const std::string& name, BoardGame* boardGame);
        void blockCoup(Player& attacker);
        void setArrested(bool arrested) override;
    };
}

#endif //CPP_EX3_GENERAL_HPP
