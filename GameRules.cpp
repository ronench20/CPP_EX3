//
// Created by ronen on 08/05/2025.
//

#include "GameRules.hpp"

using namespace std;
namespace player{

    GameRules::GameRules(const string& name, BoardGame* boardGame) : Player(name), boardGame(boardGame) {}

    void GameRules::gather() {
        if (!isSanctioned()) {
            addCoins(1);
        }
        boardGame->nextTurn();
    }

    void GameRules::tax() {
        if (!isSanctioned()) {
            addCoins(2);
        }
        boardGame->nextTurn();
    }

    void GameRules::bribe() {
        if (getCoins() >= 4) {
            removeCoins(4);
        } else {
            cout << "Not enough coins to bribe." << endl;
        }
        boardGame->nextTurn();
    }

    void GameRules::arrest(Player &target) {
        if (target.isArrested()){
            cout << target.getName() << " is already arrested." << endl;
        }
        else if (target.getCoins() == 0) {
            cout << target.getName() << " has no coins to arrest." << endl;
        }
        else {
            target.setArrested(true);
            target.removeCoins(1);
            addCoins(1);
        }
        boardGame->nextTurn();
    }
    void GameRules::sanction(player::Player &target) {
        if (getCoins() >= 3) {
            target.setSanctioned(true);
            removeCoins(3);
        } else {
            cout << "Not enough coins to sanction." << endl;
        }
        boardGame->nextTurn();
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