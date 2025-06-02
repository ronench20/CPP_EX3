//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_GENERAL_HPP
#define CPP_EX3_GENERAL_HPP

#include "../GameRules.hpp"

namespace player{
    class General : public GameRules{
    public:
        /**
         * Constructs a General with the given name and board game reference.
         * @param name The name of the player.
         * @param boardGame Pointer to the associated BoardGame.
         */
        General(const std::string& name, BoardGame* boardGame);

        /**
         * Blocks a coup action initiated by the specified attacker.
         * @param attacker The player who is attempting the coup.
         */
        void blockCoup(Player& attacker);

        /**
         * Sets the arrested state for the General.
         * Overrides the base class implementation.
         * @param arrested True if the General is arrested, false otherwise.
         */
        void setArrested(bool arrested) override;
    };
}

#endif //CPP_EX3_GENERAL_HPP