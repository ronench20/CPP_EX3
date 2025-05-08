//ronen.chereshn@msmail.ariel.ac.il


#include "GameRules.hpp"

using namespace std;
namespace player{

    GameRules::GameRules(const string& name, BoardGame* boardGame) : Player(name), boardGame(boardGame) {}

    void GameRules::gather() {
        if (!isSanctioned()) {
            addCoins(1);
            boardGame->nextTurn();
        }
    }

    void GameRules::tax() {
        if (!isSanctioned() && !isGoverned()) {
            addCoins(2);
            boardGame->nextTurn();

        }
    }

    void GameRules::bribe() {
        if (getCoins() >= 4) {
            removeCoins(4);
            boardGame->nextTurn();

        } else {
            cout << "Not enough coins to bribe." << endl;
        }
    }

    void GameRules::arrest(Player &target) {
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
            target.removeCoins(1);
            addCoins(1);
            boardGame->nextTurn();
        }
        else {
            target.setArrested(true);
            target.removeCoins(1);
            addCoins(1);
            boardGame->nextTurn();

        }
    }
    void GameRules::sanction(player::Player &target) {
        if (getCoins() >= 3) {
            target.setSanctioned(true);
            removeCoins(3);
            boardGame->nextTurn();

        } else {
            cout << "Not enough coins to sanction." << endl;
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