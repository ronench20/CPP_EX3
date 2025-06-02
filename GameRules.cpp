//ronen.chereshn@msmail.ariel.ac.il


#include "GameRules.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
namespace player{

    GameRules::GameRules(const string& name, BoardGame* boardGame) : Player(name), boardGame(boardGame) {}

    void GameRules::startTurn() {
        Player::startTurn();
    }

    void GameRules::gather() {
        if (!getSanctioned()) {
            addCoins(1);
            boardGame->nextTurn();
        }
        else {
            throw std::invalid_argument("You can't gather because you are under sanction.");

        }
    }

    void GameRules::tax() {
        if (!getSanctioned()) {
            addCoins(2);
            setDidTax(true);
            boardGame->nextTurn();
        }
        else {
            throw std::invalid_argument("You can't tax because you are under sanction.");
        }
    }

    void GameRules::bribe() {
        if (getCoins() >= 4) {
            removeCoins(4);
            setBribeBlocked(false);
            boardGame->bribeApproval(boardGame->getCurrentPlayerIndex());
        } else {
            throw std::invalid_argument("Not enough coins to bribe.");
        }
    }

    void GameRules::arrest(Player &target) {
        if (isSpied()){
            throw std ::invalid_argument("You can't arrest a player because you are spied.");
        }
        else {
            if (target.getArrestedLastTurn()) {
                std::cout << "You can't arrest " << target.getName() << " because they were arrested last turn.\n";
                return;
            }
            if (target.isArrested()) {
                throw std::invalid_argument(target.getName() + " is already arrested.");
            } else if (target.getCoins() == 0) {
                throw std::invalid_argument(target.getName() + " has no coins.");
            } else if (isSpied()) {
                throw std::invalid_argument(target.getName() + " is spied.");

            }else if (target.getRole() == "Merchant"){
                if (target.getCoins() < 2) {
                    throw std::invalid_argument("Not enough coins to pay the arrest fee.");
                } else {
                    target.setArrested(true);
                    target.setArrestedLastTurn(true);
                    target.removeCoins(2);
                    boardGame->nextTurn();
                    std::cout << getName() << " was arrested and paid 2 coins to the bank." << std::endl;
                }
            }
             else {
                target.setArrested(true);
                target.setArrestedLastTurn(true);
                target.removeCoins(1);
                addCoins(1);
                boardGame->nextTurn();
                std::cout << getName() << " arrested " << target.getName() << " and took 1 coin." << std::endl;

            }
        }
    }
    void GameRules::sanction(Player& target) {
        if (target.getRole() == "Judge" && getCoins() >= 4) {
            removeCoins(4);
            target.setSanctioned(true);
            target.setSanctionedUntilNextTurn(true);
            std::cout << getName() << " sanctioned " << target.getName() << std::endl;
            boardGame->nextTurn();
        }
        else if (target.getRole() != "Judge" && getCoins() >= 3) {
            if (target.getRole() == "Baron"){
                target.addCoins(1);
            }
            removeCoins(3);
            target.setSanctioned(true);
            target.setSanctionedUntilNextTurn(true);
            std::cout << getName() << " sanctioned " << target.getName() << std::endl;
            boardGame->nextTurn();
        } else {
            throw std:: invalid_argument("Not enough coins to sanction.");
        }
    }


    void GameRules::coup(Player &target) {
        if (getCoins() >= 7) {
            target.setCouped(true);
            removeCoins(7);
            //delete &target;
            boardGame->nextTurn();
        } else {
            throw std::invalid_argument("Not enough coins to coup.");
        }
    }

    bool GameRules::mustCoup() const {
        return getCoins() >= 10;
    }

    void GameRules::skipTurn(){
        boardGame->nextTurn();
    }

    bool GameRules::getBribeBlocked() const {
        return bribeBlocked;
    }

    void GameRules::setBribeBlocked(bool value) {
        bribeBlocked = value;
    }

}