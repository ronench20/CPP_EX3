//ronen.chereshn@msmail.ariel.ac.il


#ifndef CPP_EX3_GUI_HPP
#define CPP_EX3_GUI_HPP

#include "../BoardGame.hpp"
#include <SFML/Graphics.hpp>


namespace gui {
    class Gui {
    private:
        bool gameStarted = false;
        int targetIndex = -1;
        std::string name;

        bool selectToArrest = false;
        bool selectToSanction = false;
        bool selectToCoup = false;

        bool selectToUndoTax = false;


        player::BoardGame& game;
        sf::RenderWindow window;
        sf::Font font;

        sf::Text nameText, nameLabel;
        sf::RectangleShape roleButton, startButton;
        sf::Text roleText, startText;


        sf::RectangleShape skipButton;
        sf::Text skipText;
        sf::RectangleShape gatherButton;
        sf::Text gatherText;
        sf::RectangleShape taxButton;
        sf::Text taxText;
        sf::RectangleShape bribeButton;
        sf::Text bribeText;
        sf::RectangleShape arrestButton;
        sf::Text arrestText;
        sf::RectangleShape sanctionButton;
        sf::Text sanctionText;
        sf::RectangleShape coupButton;
        sf::Text coupText;

        sf::RectangleShape undoTaxButton;
        sf::Text undoTaxText;


        void registrationInput(sf::Event& event);
        void registration();
        void gameScreen();
        void makeButton(const sf::RectangleShape& button, const sf::Text& text);
        void showCurrTurn();
        void showPlayers();
        void playerSelect(const std::string& mode);

    public:
        Gui(player::BoardGame& game);
        void run();

    };
}
#endif //CPP_EX3_GUI_HPP