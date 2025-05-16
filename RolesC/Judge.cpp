//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/Judge.hpp"
#include <iostream>
#include <stdexcept>

namespace player {
    Judge::Judge(const std::string &name, BoardGame *boardGame) : GameRules(name, boardGame) {
        setRole("Judge");
    }

    void Judge::blockBribe(Player &target) {
        if (target.getExtraMove() && getCoins() >= 4) {
            target.setExtraMove(false);
            boardGame->nextTurn();
            std::cout << target.getName() << " was blocked from using their extra move." << std::endl;
        }
        else {
            throw std:: invalid_argument("You can't block a player who doesn't have an extra move.");
        }
    }
}