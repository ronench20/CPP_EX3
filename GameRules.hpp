//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GAMERULES_HPP
#define CPP_EX3_GAMERULES_HPP

#include "Player.hpp"
#include "BoardGame.hpp"
#include <string>

namespace player{

    class BoardGame;
    class GameRules : public Player{
    protected:
        BoardGame* boardGame;

    public:
        GameRules(const std::string& name, BoardGame* boardGame);
        void gather();
        virtual void tax();
        void bribe();
        virtual void arrest(Player& target);
        virtual void sanction(Player& target);
        virtual void coup(Player& target);
        void startTurn();
        void mustCoup();


    };
}



#endif //CPP_EX3_GAMERULES_HPP