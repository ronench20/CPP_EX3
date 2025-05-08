
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


    public:
        Player(std::string name);

        std::string getName() const;

        int getCoins() const;



//        void gather();

//        void tax();

//        void bribe();

//        void arrest(Player& target);

        bool isArrested() const;


//        void sanction(Player& target);

        bool isSanctioned() const;


//        void coup(Player& target);

        bool isCouped() const;

        void removeCoins(int amount);

        void setArrested(bool arrested);

        void setSanctioned(bool sanctioned);

        void setCouped(bool couped);
    };
}

#endif //CPP_EX3_PLAYER_HPP
