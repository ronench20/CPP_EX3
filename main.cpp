#include "display/Gui.hpp"
#include "BoardGame.hpp"
#include "RolesH/Baron.hpp"
#include "RolesH/General.hpp"
#include "RolesH/Governor.hpp"
#include "RolesH/Judge.hpp"
#include "RolesH/Merchant.hpp"
#include "RolesH/Spy.hpp"


int main() {
    player::BoardGame game;


    

    gui::Gui g(game);
    g.run();

    return 0;
}
