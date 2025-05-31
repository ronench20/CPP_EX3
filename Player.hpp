//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_PLAYER_HPP
#define CPP_EX3_PLAYER_HPP
#include <iostream>

namespace player {
    class Player {
    protected:
        std::string name;
        std::string role = "default";
        int coins;
        bool arrested = false;
        bool sanctioned = false;
        bool couped = false;
        bool sanctionedUntilNextTurn = false;
        bool arrestedLastTurn = false;
        bool extraMove = false;

        bool didTax = false;
        bool spied = false;
        bool spiedUntilNextTurn = false;


    public:
        Player(std::string name);
        Player(const Player &other);
        Player &operator=(const Player &other);
        virtual ~Player();
        std::string getName() const;
        std::string getRole() const;
        void setRole(std::string role);
        int getCoins() const;
        void addCoins(int amount);
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

        bool getDidTax() const;
        void setDidTax(bool value);
        bool isSpied() const;
        void setSpied(bool spied);
        void setSpiedUntilNextTurn(bool spied);
    };
}

#endif //CPP_EX3_PLAYER_HPP