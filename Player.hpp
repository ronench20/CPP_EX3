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
        /**
         * Constructs a Player with the given name.
         * @param name The name of the player.
         */
        Player(std::string name);

        /**
         * Copy constructor.
         * @param other The player to copy from.
         */
        Player(const Player &other);

        /**
         * Assignment operator.
         * @param other The player to assign from.
         * @return Reference to this player.
         */
        Player &operator=(const Player &other);

        /**
         * Virtual destructor.
         */
        virtual ~Player();

        /**
         * Gets the player's name.
         * @return The player's name.
         */
        std::string getName() const;

        /**
         * Gets the player's role.
         * @return The player's role.
         */
        std::string getRole() const;

        /**
         * Sets the player's role.
         * @param role The new role.
         */
        void setRole(std::string role);

        /**
         * Gets the number of coins the player has.
         * @return The coin count.
         */
        int getCoins() const;

        /**
         * Adds coins to the player's total.
         * @param amount The number of coins to add.
         */
        void addCoins(int amount);

        /**
         * Checks if the player is arrested.
         * @return True if arrested, false otherwise.
         */
        bool isArrested() const;

        /**
         * Sets whether the player was arrested last turn.
         * @param value True if arrested last turn, false otherwise.
         */
        void setArrestedLastTurn(bool value);

        /**
         * Gets whether the player was arrested last turn.
         * @return True if arrested last turn, false otherwise.
         */
        bool getArrestedLastTurn() const;

        /**
         * Checks if the player has been couped.
         * @return True if couped, false otherwise.
         */
        bool isCouped() const;

        /**
         * Removes coins from the player's total.
         * @param amount The number of coins to remove.
         */
        void removeCoins(int amount);

        /**
         * Sets the arrested status of the player.
         * @param arrested True to arrest, false to release.
         */
        virtual void setArrested(bool arrested);

        /**
         * Sets the sanctioned status of the player.
         * @param value True to sanction, false to unsanction.
         */
        virtual void setSanctioned(bool value);

        /**
         * Gets the sanctioned status of the player.
         * @return True if sanctioned, false otherwise.
         */
        bool getSanctioned() const;

        /**
         * Gets if the player is sanctioned until next turn.
         * @return True if sanctioned until next turn, false otherwise.
         */
        bool getSanctionedUntilNextTurn() const;

        /**
         * Sets if the player is sanctioned until next turn.
         * @param value True to sanction until next turn, false otherwise.
         */
        void setSanctionedUntilNextTurn(bool value);

        /**
         * Sets the couped status of the player.
         * @param couped True if couped, false otherwise.
         */
        virtual void setCouped(bool couped);

        /**
         * Called at the start of the player's turn.
         */
        virtual void startTurn();

        /**
         * Sets whether the player has an extra move.
         * @param extraMove True if extra move is granted, false otherwise.
         */
        void setExtraMove(bool extraMove);

        /**
         * Gets whether the player has an extra move.
         * @return True if extra move is available, false otherwise.
         */
        bool getExtraMove() const;

        /**
         * Gets whether the player performed a tax action.
         * @return True if tax was performed, false otherwise.
         */
        bool getDidTax() const;

        /**
         * Sets whether the player performed a tax action.
         * @param value True if tax was performed, false otherwise.
         */
        void setDidTax(bool value);

        /**
         * Checks if the player has been spied on.
         * @return True if spied, false otherwise.
         */
        bool isSpied() const;

        /**
         * Sets whether the player has been spied on.
         * @param spied True if spied, false otherwise.
         */
        void setSpied(bool spied);

        /**
         * Sets whether the player is spied on until next turn.
         * @param spied True if spied until next turn, false otherwise.
         */
        void setSpiedUntilNextTurn(bool spied);
    };
}

#endif //CPP_EX3_PLAYER_HPP