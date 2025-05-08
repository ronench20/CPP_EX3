//
// Created by ronen on 08/05/2025.
//
#ifndef CPP_EX3_GAMERULES_HPP
#define CPP_EX3_GAMERULES_HPP

#include "Player.hpp"
#include "BoardGame.hpp"

namespace player{

    class BoardGame;
    class GameRules : public Player{
    private:
        BoardGame* boardGame;

    public:
        GameRules(const std::string& name, BoardGame* boardGame);
        void gather();
        void tax();
        void bribe();
        void arrest(Player& target);
        void sanction(Player& target);
        void coup(Player& target);
    };
}



#endif //CPP_EX3_GAMERULES_HPP
