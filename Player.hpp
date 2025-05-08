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

        bool governed = false;
        bool spied = false;


    public:
        Player(std::string name);
        std::string getName() const;
        int getCoins() const;
        bool isArrested() const;
        bool isSanctioned() const;
        bool isCouped() const;
        void removeCoins(int amount);
        void setArrested(bool arrested);
        void setSanctioned(bool sanctioned);
        void setCouped(bool couped);


        bool isGoverned() const;
        void setGoverned(bool governed);
        bool isSpied() const;
        void setSpied(bool spied);
    };
}

#endif //CPP_EX3_PLAYER_HPP
