//ronen.chereshn@msmail.ariel.ac.il

#include "Judge.hpp"

namespace player{
    Judge::Judge(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {}

    void Judge::blockBribe(Player& target) {

            boardGame->nextTurn();
        }
    }