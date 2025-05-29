//ronen.chereshn@msmail.ariel.ac.il


#ifndef CPP_EX3_BOARDGAME_HPP
#define CPP_EX3_BOARDGAME_HPP

#include <iostream>
#include "Player.hpp"

namespace player{

    class BoardGame{
    private:
        Player *playersList[6];
        int numOfPlayers = 0;
        int currentPlayerIndex = 0;

        int generals[6];
        bool awaitingCoup = false;
        int attackerIndex = -1;
        int targetIndex = -1;
        int numOfGenerals = 0;
        int nextGeneralIndex = 0;

    public:
        BoardGame();
        void addPlayer(Player* player);
        std::string turn() const;
        Player* getCurrentPlayer() const;
        int getNumOfPlayers() const;
        Player* getPlayerIndex(int index) const;
        int getCurrentPlayerIndex() const;
        std::string players() const;
        std::string winner() const;
        void nextTurn();
        void createPlayer(const std::string& name);
        void removePlayer(int index);

        bool getAwaitingCoup() const;
        int getCurrGeneralIndex() const;
        bool canGeneralPreventCoup() const;
        void coupApproval(int attackerIndex, int targetIndex);
        void coupDecision(bool prevent);
        void clearApproval();
    };
}

#endif //CPP_EX3_BOARDGAME_HPP