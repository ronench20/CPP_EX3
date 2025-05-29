//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_SPY_HPP
#define CPP_EX3_SPY_HPP

#include "../GameRules.hpp"

namespace player{
    class Spy : public GameRules{
    private:
        bool spiedThisTurn = false;
    public:
        Spy(const std::string& name, BoardGame* boardGame);
        int getCoins(Player &other) const;
        void arrestBlock(Player &target);
        void resetSpiedThisTurn();
        bool getSpiedThisTurn() const;
    };
}


#endif //CPP_EX3_SPY_HPP
