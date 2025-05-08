//
// Created by ronen on 08/05/2025.
//

#ifndef CPP_EX3_BOARDGAME_HPP
#define CPP_EX3_BOARDGAME_HPP

#include <iostream>
#include "Player.hpp"

using namespace std;
namespace player{

    class BoardGame{
    private:
        BoardGame *players[6];
        int numOfPlayers = 0;
        int currentPlayerIndex = 0;

    public:
        BoardGame();
        void addPlayer(Player* player);
        string turn() const;
        string playersNames() const;
        string winner() const;
        void nextTurn();
    };
}

#endif //CPP_EX3_BOARDGAME_HPP
