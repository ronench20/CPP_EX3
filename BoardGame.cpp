//ronen.chereshn@msmail.ariel.ac.il

#include "BoardGame.hpp"
#include <cstdlib>
#include "RolesH/Baron.hpp"
#include "RolesH/General.hpp"
#include "RolesH/Governor.hpp"
#include "RolesH/Judge.hpp"
#include "RolesH/Merchant.hpp"
#include "RolesH/Spy.hpp"

using namespace std;

namespace player {
    BoardGame::BoardGame() {
        for (int i = 0; i < 6; i++) {
            playersList[i] = nullptr;
        }
    }

    void BoardGame::addPlayer(Player *player) {
        if (numOfPlayers < 6) {
            playersList[numOfPlayers++] = player;
        } else {
            std::cout << "Cannot add more players." << std::endl;
        }
    }

    string BoardGame::turn() const {
        if (numOfPlayers < 2) {
            return "No players in the game.";
        } else{
            return playersList[currentPlayerIndex]->getName();
        }
    }

    Player* BoardGame::getCurrentPlayer() const {
        if (numOfPlayers < 2) {
            return nullptr;
        } else {
            return playersList[currentPlayerIndex];
        }
    }
    int BoardGame::getNumOfPlayers() const {
        return numOfPlayers;
    }

    Player* BoardGame::getPlayerIndex(int index) const {
        if (index < 0 || index >= numOfPlayers) {
            return nullptr;
        }
        return playersList[index];
    }

    string BoardGame::players() const {
        string names;
        for (int i = 0; i < numOfPlayers; i++) {
            names += playersList[i]->getName();
            if (i < numOfPlayers - 1) {
                names += ", ";
            }
        }
        return names;
    }

    string BoardGame::winner() const {
        int count = 0;
        string winnerName;
        for (int i = 0; i < numOfPlayers; ++i) {
            if (!playersList[i]->isCouped()) {
                count++;
                winnerName = playersList[i]->getName();
            }
        }
        if (count == 1) {
            return winnerName;
        } else {
            return "No winner yet.";
        }
    }

    void BoardGame::nextTurn() {
        Player* current = getCurrentPlayer();
        if (current != nullptr && current->getExtraMove()) {
            current->setExtraMove(false);
            std::cout << current->getName() << " used their extra action (bribe).\n";
            return;
        }

        if (numOfPlayers < 2) {
           cout << "No players in the game." << endl;
        } else {
            for (int i = 0; i < numOfPlayers; ++i) {
                int next = (currentPlayerIndex + 1) % numOfPlayers;
                if (!playersList[next]->isCouped()) {
                    currentPlayerIndex = next;
                    getCurrentPlayer()->startTurn();
                    return;
                }
            }
        }
    }

    void BoardGame::createPlayer(const string &name) {
        int i = rand() % 6;
        Player* player1 = nullptr;

        if (i == 0){
            player1 = new Baron(name, this);
        } else if (i == 1){
            player1 = new General(name, this);
        }
        else if (i == 2){
            player1 = new Governor(name, this);
        }
        else if (i == 3){
            player1 = new Judge(name, this);
        }
        else if (i == 4){
            player1 = new Merchant(name, this);
        }
        else if (i == 5){
            player1 = new Spy(name, this);
        }
        addPlayer(player1);
        cout << "player added" << endl;
    }
}