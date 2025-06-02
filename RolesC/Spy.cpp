//ronen.chereshn@msmail.ariel.ac.il

#include "../RolesH/Spy.hpp"
#include <stdexcept>

namespace player{

    Spy::Spy(const std::string& name, BoardGame* boardGame) : GameRules(name, boardGame) {
        setRole("Spy");
    }

    int Spy::getCoins(Player &other) const {
        return other.getCoins();
    }

    void Spy::arrestBlock(Player &target){
        if (getSpiedThisTurn()){
            throw std::invalid_argument("You have already spied this turn.");
        }else{
            target.setSpied(true);
            target.setSpiedUntilNextTurn(true);
            spiedThisTurn = true;
        }
    }

    void Spy::resetSpiedThisTurn() {
        spiedThisTurn = false;
    }

    bool Spy::getSpiedThisTurn() const {
        return spiedThisTurn;
    }
}
