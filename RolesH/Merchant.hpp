//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_MERCHANT_HPP
#define CPP_EX3_MERCHANT_HPP

#include "../GameRules.hpp"
namespace player{
    class Merchant : public GameRules{
    public:
        Merchant(const std::string& name, BoardGame* boardGame);
        void startTurn() override;
        void extraCoin();
        //void setArrested(bool arrested) override;

    };
}

#endif //CPP_EX3_MERCHANT_HPP
