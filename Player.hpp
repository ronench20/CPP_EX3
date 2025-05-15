//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_PLAYER_HPP
#define CPP_EX3_PLAYER_HPP
#include <iostream>

namespace player {
    class Player {
    protected:
        std::string name;
        // Role role;
        int coins;
        bool arrested = false;
        bool sanctioned = false;
        bool couped = false;
        void addCoins(int amount);
        bool sanctionedUntilNextTurn = false;
        bool arrestedLastTurn = false;
        bool extraMove = false;

        bool governed = false;
        bool spied = false;


    public:
        Player(std::string name);
        std::string getName() const;
        int getCoins() const;
        bool isArrested() const;
        void setArrestedLastTurn(bool value);
        bool getArrestedLastTurn() const;
        bool isCouped() const;
        void removeCoins(int amount);
        virtual void setArrested(bool arrested);
        virtual void setSanctioned(bool value);
        bool getSanctioned() const;
        bool getSanctionedUntilNextTurn() const;
        void setSanctionedUntilNextTurn(bool value);
        virtual void setCouped(bool couped);
        virtual void startTurn();
        void setExtraMove(bool extraMove);
        bool getExtraMove() const;


        bool isGoverned() const;
        void setGoverned(bool governed);
        bool isSpied() const;
        void setSpied(bool spied);
    };
}

#endif //CPP_EX3_PLAYER_HPP
