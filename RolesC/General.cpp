//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/General.hpp"
#include <iostream>
#include <stdexcept>

namespace player{
    General::General(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("General");
    }

    void General::blockCoup(player::Player &attacker) {
       if (getCoins() >= 5){
            removeCoins(5);
            attacker.removeCoins(7);
            std::cout << "The coup from " + attacker.getName() + " has been blocked." << std::endl;
            boardGame->nextTurn();
        }
    }

    void General::setArrested(bool arrested) {
        Player::setArrested(arrested);

        if (arrested){
            addCoins(1);
            std::cout << getName() << " is arrested, but got the coin back." << std::endl;
        }
    }
}