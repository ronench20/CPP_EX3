//ronen.chereshn@msmail.ariel.ac.il

#include "Spy.hpp"

namespace player{

    Spy::Spy(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {}

    int Spy::getCoins(Player &other) const {
        return other.getCoins();
    }

    void Spy::arrestBlock(Player &target) {
        target.setSpied(true);
    }
}
