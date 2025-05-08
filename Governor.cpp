//ronen.chereshn@msmail.ariel.ac.il

#include "Governor.hpp"

namespace player{

    Governor::Governor(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {}

    void Governor::tax() {
        if (!isSanctioned()) {
            addCoins(3);
        }
        boardGame->nextTurn();
    }

    void Governor::taxBlock(Player& target) {
        if (target.isGoverned()) {
            cout << target.getName() << " is tax blocked." << endl;
        } else {
            target.isGoverned();
        }
        boardGame->nextTurn();
    }
}