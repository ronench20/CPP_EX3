//ronen.chereshn@msmail.ariel.ac.il

#include <stdexcept>
#include <iostream>
#include "../RolesH/Merchant.hpp"

namespace player{
    Merchant::Merchant(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("Merchant");
    }

    void Merchant::startTurn() {
        extraCoin();
        Player::startTurn();
    }

    void Merchant::extraCoin() {
        if (getCoins() > 2 && boardGame->getCurrentPlayer() == this) {
            addCoins(1);
            std::cout << getName() << " the Merchant got an extra coin." << std::endl;
        }
    }

    //void Merchant::setArrested(bool arrested) {
        //if (arrested) {
            //if (getCoins() >= 2){
                //removeCoins(2);
                //std::cout << getName() << " was arrested and paid 2 coins to the bank." << std::endl;
            //} else {
                //throw std::invalid_argument("Not enough coins to pay the arrest fee.");
            //}
        //}
        //Player::setArrested(arrested);
    //}

}