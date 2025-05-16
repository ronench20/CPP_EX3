//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/Spy.hpp"

namespace player{

    Spy::Spy(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("Spy");
    }

    int Spy::getCoins(Player &other) const {
        return other.getCoins();
    }

    void Spy::arrestBlock(Player &target) {
        target.setSpied(true);
        target.setSpiedUntilNextTurn(true);
    }
}
