//ronen.chereshn@msmail.ariel.ac.il


#ifndef CPP_EX3_GUI_HPP
#define CPP_EX3_GUI_HPP

#include "../BoardGame.hpp"
#include <SFML/Graphics.hpp>


namespace gui {
    class Gui {
    private:
        bool gameStarted = false;
        std::string name;

        player::BoardGame& game;
        sf::RenderWindow window;
        sf::Font font;

        sf::Text nameText, nameLabel;
        sf::RectangleShape roleButton, startButton;
        sf::Text roleText, startText;

        sf::RectangleShape gatherButton;
        sf::Text gatherText;

        bool canMakeAction(player::Player* player);
        void registrationInput(sf::Event& event);
        void registration();
        void gameScreen();
        void makeButton(const sf::RectangleShape& button, const sf::Text& text);
        void showCurrTurn();
        void showPlayers();

    public:
        Gui(player::BoardGame& game);
        void run();

    };
}
#endif //CPP_EX3_GUI_HPP
