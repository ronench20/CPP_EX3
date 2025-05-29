//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/Baron.hpp"
#include <stdexcept>

namespace player{
    Baron::Baron(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("Baron");
    }

    void Baron::invest() {
        if (getCoins() >= 3){
            addCoins(3);
            boardGame->nextTurn();
        }
        else{
            throw std:: invalid_argument("Not enough coins to invest.");
        }
    }

    void Baron::sanction(Player &target) {
        GameRules::sanction(target);
        addCoins(1);
    }

}