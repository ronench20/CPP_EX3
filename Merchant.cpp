//ronen.chereshn@msmail.ariel.ac.il

#include "Merchant.hpp"

namespace player{
    Merchant::Merchant(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {}

    void Merchant::extraCoin() {
        if (getCoins() > 2 && boardGame->getCurrentPlayer() == this) {
            addCoins(1);
            std::cout << getName() << " got an extra coin." << std::endl;
        } else {
            std::cout << getName() << " doesn't have enough coins for an extra coin." << std::endl;
        }
    }

    void Merchant::setArrested(bool arrested) {
        if (arrested) {
            removeCoins(2);
            std::cout << getName() << " was arrested and paid 2 coins to the bank." << std::endl;
        }
        Player::setArrested(arrested);
    }

}