//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX3_BARON_HPP
#define CPP_EX3_BARON_HPP

#include "../GameRules.hpp"

namespace player{
    class Baron : public GameRules{
    public:
        Baron(const std::string& name, BoardGame* boardGame);
        void invest();
        void sanction(Player& target) override;
    };
}

#endif //CPP_EX3_BARON_HPP
