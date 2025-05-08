//
// Created by ronen on 08/05/2025.
//

#include "BoardGame.hpp"

namespace player {
    BoardGame::BoardGame() {
        for (int i = 0; i < 6; i++) {
            players[i] = nullptr;
        }
    }

    void BoardGame::addPlayer(Player *player) {
        if (numOfPlayers < 6) {
            players[numOfPlayers++] = player;
        } else {
            std::cout << "Cannot add more players." << std::endl;
        }
    }

    string BoardGame::turn() const {
        if (numOfPlayers < 2) {
            return "No players in the game.";
        } else{
            return players[currentPlayerIndex]->getName();
        }
    }

    string BoardGame::playersNames() const {
        string names;
        for (int i = 0; i < numOfPlayers; i++) {
            names += players[i]->getName();
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
            if (!players[i]->isCouped()) {
                count++;
                winnerName = players[i]->getName();
            }
        }
        if (count == 1) {
            return winnerName;
        } else {
            return "No winner yet.";
        }
    }

    void BoardGame::nextTurn() {
        if (numOfPlayers < 2) {
           cout << "No players in the game." << endl;
        } else {
            for (int i = 0; i < numOfPlayers; ++i) {
                int next = (currentPlayerIndex + 1) % numOfPlayers;
                if (players[next]->isCouped()) {
                    currentPlayerIndex = next;
                    return;
                }
            }
        }
    }
}