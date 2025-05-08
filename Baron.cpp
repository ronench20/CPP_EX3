//ronen.chereshn@msmail.ariel.ac.il

#include "Baron.hpp"

namespace player{
    Baron::Baron(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {}

    void Baron::invest() {
        if (getCoins() >= 3){
            addCoins(3);
            boardGame->nextTurn();
        }
        else{
            cout << "Not enough coins to invest." << endl;
        }
    }

    void Baron::sanction(Player &attacker) {
        GameRules::sanction(attacker);
        addCoins(1);
    }

}