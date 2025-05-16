//ronen.chereshn@msmail.ariel.ac.il


#ifndef CPP_EX3_BOARDGAME_HPP
#define CPP_EX3_BOARDGAME_HPP

#include <iostream>
#include "Player.hpp"

using namespace std;
namespace player{

    class BoardGame{
    private:
        Player *playersList[6];
        int numOfPlayers = 0;
        int currentPlayerIndex = 0;

    public:
        BoardGame();
        void addPlayer(Player* player);
        string turn() const;
        Player* getCurrentPlayer() const;
        int getNumOfPlayers() const;
        Player* getPlayerIndex(int index) const;
        string players() const;
        string winner() const;
        void nextTurn();
    };
}

#endif //CPP_EX3_BOARDGAME_HPP
