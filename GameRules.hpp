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
        bool bribeBlocked = false;

    public:
        GameRules(const std::string& name, BoardGame* boardGame);
        void gather();
        virtual void tax();
        void bribe();
        virtual void arrest(Player& target);
        virtual void sanction(Player& target);
        virtual void coup(Player& target);
        void startTurn();
        bool mustCoup() const;
        void skipTurn();
        bool getBribeBlocked() const;
        void setBribeBlocked(bool value);

    };
}



#endif //CPP_EX3_GAMERULES_HPP