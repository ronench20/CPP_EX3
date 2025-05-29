//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/Governor.hpp"
#include <stdexcept>

namespace player{

    Governor::Governor(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("Governor");
    }

    void Governor::tax() {
        if (!getSanctioned()) {
            addCoins(3);
            setDidTax(true);
        }
        boardGame->nextTurn();
    }

    void Governor::taxBlock(Player& target) {
        if (!target.isCouped() && target.getDidTax()){
            if (target.getCoins() >= 2 && target.getRole() != "Governor") {
                target.removeCoins(2);
                std::cout << target.getName() << " tax has been deleted." << std::endl;
                target.setDidTax(false);
                boardGame->nextTurn();
            }
            else if (target.getCoins() >= 3 && target.getRole() == "Governor"){
                target.removeCoins(3);
                std::cout << target.getName() << " tax has been deleted." << std::endl;
                target.setDidTax(false);
                boardGame->nextTurn();
            }
            else {
                throw std:: invalid_argument("Not enough coins to block the tax.");
            }
        }
        else {
            throw std:: invalid_argument("You can't block the tax.");
        }
    }
}