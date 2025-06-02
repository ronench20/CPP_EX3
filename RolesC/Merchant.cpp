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
}