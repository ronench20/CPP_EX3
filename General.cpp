//ronen.chereshn@msmail.ariel.ac.il

#include "General.hpp"

namespace player{
    General::General(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {}

    void General::blockCoup(player::Player &target) {
        if (getCoins() >= 5){
            removeCoins(5);
            target.setCouped(false);
            std::cout << target.getName() << " is blocked from coup." << std::endl;
            boardGame->nextTurn();
        }
        else{
            std::cout << "Not enough coins to block coup." << std::endl;
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