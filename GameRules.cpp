//ronen.chereshn@msmail.ariel.ac.il


#include "GameRules.hpp"

using namespace std;
namespace player{

    GameRules::GameRules(const string& name, BoardGame* boardGame) : Player(name), boardGame(boardGame) {}

    void GameRules::gather() {
        if (!getSanctioned()) {
            addCoins(1);
            boardGame->nextTurn();
        }
        else {
            cout << getName() << " is under sanction and cannot gather." << endl;

        }
    }

    void GameRules::tax() {
        if (getSanctioned() && !isGoverned()) {
            addCoins(2);
            boardGame->nextTurn();
        }
        else {
            cout << getName() << " is under sanction or governed and cannot tax." << endl;
        }
    }

    void GameRules::bribe() {
        if (getCoins() >= 4) {
            removeCoins(4);
            setExtraMove(true);
        } else {
            cout << "Not enough coins to bribe." << endl;
        }
    }

    void GameRules::arrest(Player &target) {
        if (target.getArrestedLastTurn()) {
            std::cout << "You can't arrest " << target.getName() << " because they were arrested last turn.\n";
            return;
        }
        if (target.isArrested()){
            cout << target.getName() << " is already arrested." << endl;
        }
        else if (target.getCoins() == 0) {
            cout << target.getName() << " has no coins to arrest." << endl;
        }
        else if (isSpied()){
            cout << target.getName() << " is spied." << endl;

        }
        else if (target.isGoverned()) {
            cout << target.getName() << " is governed." << endl;
            target.setArrested(true);
            target.setArrestedLastTurn(true);
            target.removeCoins(1);
            addCoins(1);
            boardGame->nextTurn();
        }
        else {
            target.setArrested(true);
            target.setArrestedLastTurn(true);
            target.removeCoins(1);
            addCoins(1);
            boardGame->nextTurn();

        }
    }
    void GameRules::sanction(Player& target) {
        if (getCoins() >= 3) {
            removeCoins(3);
            target.setSanctioned(true);
            target.setSanctionedUntilNextTurn(true);
            std::cout << getName() << " sanctioned " << target.getName() << std::endl;
            boardGame->nextTurn();
        } else {
            std::cout << "Not enough coins to sanction.\n";
        }
    }


    void GameRules::coup(player::Player &target) {
        if (getCoins() >= 7) {
            target.setCouped(true);
            removeCoins(7);
        } else {
            cout << "Not enough coins to coup." << endl;
        }
        boardGame->nextTurn();
    }

}