//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GENERAL_HPP
#define CPP_EX3_GENERAL_HPP

#include "GameRules.hpp"

namespace player{
    class General : public GameRules{
    public:
        General(const std::string& name, BoardGame* boardGame);
        //void coup(Player& target) override;
        void blockCoup(Player& target);
        void setArrested(bool arrested) override;
    };
}

#endif //CPP_EX3_GENERAL_HPP
