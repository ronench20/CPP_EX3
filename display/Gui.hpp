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
        bool showNoMoneyAssestMessage = false;
        bool showAlreadyArrestedMessage = false;
        bool selectToSanction = false;
        bool selectToCoup = false;
        bool showMerchantArrestedMessage = false;
        bool showJudgeSanctionMessage = false;

        bool selectToUndoTax = false;
        bool selectToSpy = false;
        bool showSpyMessage = false;



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
        sf::RectangleShape spyButton;
        sf::Text spyText;
        sf::RectangleShape investButton;
        sf::Text investText;
        sf::RectangleShape preventCoupButton;
        sf::Text preventCoupText;
        sf::RectangleShape allowCoupButton;
        sf::Text allowCoupText;
        sf::Text decisionLabel; 
        sf::RectangleShape cancelBribeButton;
        sf::RectangleShape approveBribeButton;
        sf::Text cancelBribeText;
        sf::Text approveBribeText;
        sf::Text bribeLabel;

        sf::Text noMoneyAssestMessage;
        sf::Clock noMoneyAssestTimer;
        sf::Text alreadyArrestedMessage;
        sf::Clock alreadyArrestedTimer;
        sf::Text spyMessege;
        sf::Clock spyMessegeTimer;
        sf::Text merchantArrestedLabel;
        sf::Clock merchantArrestedTimer;
        sf::Text judgeSanctionLabel;
        sf::Clock judgeSanctionTimer;

        sf::Text victoryText;
        sf::Clock victoryTimer;
        sf::Event event;



/**
     * Handles user input during the registration phase.
     * @param event Reference to the game that is active.
     */
    void registrationInput(sf::Event& event);

    /**
     * Displays the registration interface and processes registration logic.
     */
    void registration();

    /**
     * Renders the main action buttons on the GUI.
     */
    void showButtons();

    /**
     * Displays messages to the user, such as errors or notifications.
     */
    void showMessage();

    /**
     * Draws a button with the specified shape and text.
     * @param button The rectangle shape representing the button.
     * @param text The text to display on the button.
     */
    void makeButton(const sf::RectangleShape& button, const sf::Text& text);

    /**
     * Shows the current player's turn on the GUI.
     */
    void showCurrTurn();

    /**
     * Displays status about all players in the game.
     */
    void showPlayers();

    /**
     * Handles player selection for a specific mode.
     * @param mode The mode indicating the type of selection (e.g., arrest, sanction).
     */
    void playerSelect(const std::string& mode);

public:
    /**
     * Constructs the GUI.
     * @param game Reference to the BoardGame instance.
     */
    Gui(player::BoardGame& game);

    /**
     * Runs the main GUI.
     */
    void run();
    };
}
#endif //CPP_EX3_GUI_HPP