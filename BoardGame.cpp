//ronen.chereshn@msmail.ariel.ac.il

#include "BoardGame.hpp"

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
}