//ronen.chereshn@msmail.ariel.ac.il

#include "Gui.hpp"
#include "../GameRules.hpp"
#include <iostream>
#include <stdexcept>

using namespace player;

namespace gui{

    Gui::Gui(BoardGame &game) : game(game), window(sf::VideoMode(700, 500), "Game Display"){
        if (!font.loadFromFile("display/arial.ttf")){
            throw std:: invalid_argument("font not found");
        }
        nameLabel.setFont(font);
        nameLabel.setCharacterSize(20);
        nameLabel.setString("Enter your name:");
        nameLabel.setPosition(20, 20);
        nameLabel.setFillColor(sf::Color::White);

        nameText.setFont(font);
        nameText.setCharacterSize(20);
        nameText.setPosition(20, 50);
        nameText.setFillColor(sf::Color::Yellow);

        roleButton.setSize(sf::Vector2f(222, 50));
        roleButton.setPosition(20, 100);
        roleButton.setFillColor(sf::Color::Green);

        roleText.setFont(font);
        roleText.setCharacterSize(18);
        roleText.setString("CHOOSE A ROLE CARD");
        roleText.setPosition(30, 110);
        roleText.setFillColor(sf::Color::Black);

        startButton.setSize(sf::Vector2f(150, 50));
        startButton.setPosition(20, 200);
        startButton.setFillColor(sf::Color::Green);

        startText.setFont(font);
        startText.setCharacterSize(18);
        startText.setString("START GAME");
        startText.setPosition(30, 210);
        startText.setFillColor(sf::Color::Black);


        gatherButton.setSize(sf::Vector2f(120, 50));
        gatherButton.setPosition(20, 400);
        gatherButton.setFillColor(sf::Color::Green);
        gatherText.setFont(font);
        gatherText.setCharacterSize(18);
        gatherText.setString("GATHER");
        gatherText.setPosition(40, 410);
        gatherText.setFillColor(sf::Color::Black);


    }

    void Gui::run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (!gameStarted) {
                    registrationInput(event);
                }

                if (event.type == sf::Event::MouseButtonPressed && gameStarted) {
                    int mouseX = sf::Mouse::getPosition(window).x;
                    int mouseY = sf::Mouse::getPosition(window).y;

                    if (gatherButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        Player* p = game.getCurrentPlayer();
                        if (p != nullptr) {
                            ((GameRules*)p)->gather();
                        }
                    }
                }
            }

            window.clear(sf::Color::Black);

            if (!gameStarted) {
                registration();
            } else {
                gameScreen();
            }

            window.display();
        }
    }


    void Gui::registrationInput(sf::Event &event) {
        if (event.type == sf::Event::TextEntered && name.size() < 20){
            if (event.text.unicode >= 32 && event.text.unicode <= 126){
                name += (char)(event.text.unicode);
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace && !name.empty()){
            name.pop_back();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            if (roleButton.getGlobalBounds().contains((float)mouseX, (float)mouseY) &&
                game.getNumOfPlayers() < 6 && !name.empty()) {
                game.createPlayer(name);
                name = "";
            }
            if (startButton.getGlobalBounds().contains((float)mouseX, (float)mouseY) &&
                game.getNumOfPlayers() >= 2) {
                gameStarted = true;
            }
        }
    }

    void Gui::makeButton(const sf::RectangleShape &button, const sf::Text &text) {
        window.draw(button);
        window.draw(text);
    }

    void Gui::registration() {
        nameText.setString(name);
        window.draw(nameLabel);
        window.draw(nameText);

        if (game.getNumOfPlayers() < 6){
            makeButton(roleButton, roleText);
        }
        if (game.getNumOfPlayers() >= 2){
            makeButton(startButton, startText);
        }
        float position = 300;
        for (int i = 0; i < game.getNumOfPlayers(); ++i) {
            Player* p = game.getPlayerIndex(i);
            sf::Text t(p->getName(), font, 18);
            t.setPosition(30, position);
            t.setFillColor(sf::Color::White);
            window.draw(t);
            position += 25;
        }
    }

    void Gui::gameScreen() {
        showCurrTurn();
        showPlayers();

        makeButton(gatherButton, gatherText);
    }

    void Gui::showCurrTurn() {
        Player *curr = game.getCurrentPlayer();
        if (curr == nullptr) {
            return;
        }
        sf::Text title(curr -> getName() + "'s turn", font, 20);
        title.setPosition(20, 20);
        title.setFillColor(sf::Color::Yellow);
        window.draw(title);
    }

    void Gui::showPlayers() {
        float position = 70;
        for (int i = 0; i < game.getNumOfPlayers(); ++i) {
            Player *player = game.getPlayerIndex(i);
            std::string status;

            if (player->isCouped()){
                status += "couped ";
            }
            if (player->isArrested()){
                status += "arrested ";
            }
            if (player->getSanctioned()){
                status += "sanctioned ";
            }
            if (player->isSpied()){
                status += "spied ";
            }
            std::string line = player->getName() + "::     role: " + player->getRole() + " :amount of coins: " + std::to_string(player->getCoins()) + " " + status;
            sf::Text text(line, font, 20);
            text.setPosition(20,position);
            text.setFillColor(player == game.getCurrentPlayer() ? sf::Color::Red : sf::Color::Blue);
            window.draw(text);
            position += 30;

        }
    }

}