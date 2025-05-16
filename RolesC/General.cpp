//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/General.hpp"
#include <iostream>
#include <stdexcept>

namespace player{
    General::General(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("General");
    }

    void General::blockCoup(player::Player &target, player::Player &attacker) {
        if (getCoins() >= 5){
            removeCoins(5);
            target.setCouped(false);
            std::cout << target.getName() << " is blocked from coup." << std::endl;
            boardGame->nextTurn();
        }
        else{
            throw std::invalid_argument("Not enough coins to block coup.");        }
    }

    void General::setArrested(bool arrested) {
        Player::setArrested(arrested);

        if (arrested){
            addCoins(1);
            std::cout << getName() << " is arrested, but got the coin back." << std::endl;
        }
    }
}