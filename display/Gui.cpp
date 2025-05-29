//ronen.chereshn@msmail.ariel.ac.il

#include "Gui.hpp"
#include "../GameRules.hpp"
#include <iostream>
#include <stdexcept>
#include "../RolesH/Governor.hpp"
#include "../RolesH/Spy.hpp"
#include "../RolesH/Baron.hpp"
#include "../RolesH/General.hpp"
#include "../RolesH/Judge.hpp"
#include "../RolesH/Merchant.hpp"

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

        skipButton.setSize(sf::Vector2f(90, 50));
        skipButton.setPosition(590, 20);
        skipButton.setFillColor(sf::Color::Green);
        skipText.setFont(font);
        skipText.setCharacterSize(16);
        skipText.setString("SKIP TURN");
        skipText.setPosition(595, 30);
        skipText.setFillColor(sf::Color::Black);

        gatherButton.setSize(sf::Vector2f(90, 50));
        gatherButton.setPosition(20, 400);
        gatherButton.setFillColor(sf::Color::Green);
        gatherText.setFont(font);
        gatherText.setCharacterSize(16);
        gatherText.setString("GATHER");
        gatherText.setPosition(30, 410);
        gatherText.setFillColor(sf::Color::Black);

        taxButton.setSize(sf::Vector2f(90, 50));
        taxButton.setPosition(130, 400);
        taxButton.setFillColor(sf::Color::Green);
        taxText.setFont(font);
        taxText.setCharacterSize(16);
        taxText.setString("TAX");
        taxText.setPosition(155, 410);
        taxText.setFillColor(sf::Color::Black);

        bribeButton.setSize(sf::Vector2f(90, 50));
        bribeButton.setPosition(240, 400);
        bribeButton.setFillColor(sf::Color::Green);
        bribeText.setFont(font);
        bribeText.setCharacterSize(16);
        bribeText.setString("BRIBE");
        bribeText.setPosition(260, 410);
        bribeText.setFillColor(sf::Color::Black);

        arrestButton.setSize(sf::Vector2f(90, 50));
        arrestButton.setPosition(350, 400);
        arrestButton.setFillColor(sf::Color::Green);
        arrestText.setFont(font);
        arrestText.setCharacterSize(16);
        arrestText.setString("ARREST");
        arrestText.setPosition(360, 410);
        arrestText.setFillColor(sf::Color::Black);

        sanctionButton.setSize(sf::Vector2f(90, 50));
        sanctionButton.setPosition(460, 400);
        sanctionButton.setFillColor(sf::Color::Green);
        sanctionText.setFont(font);
        sanctionText.setCharacterSize(16);
        sanctionText.setString("SANCTION");
        sanctionText.setPosition(465, 410);
        sanctionText.setFillColor(sf::Color::Black);

        coupButton.setSize(sf::Vector2f(90, 50));
        coupButton.setPosition(570, 400);
        coupButton.setFillColor(sf::Color::Green);
        coupText.setFont(font);
        coupText.setCharacterSize(16);
        coupText.setString("COUP");
        coupText.setPosition(590, 410);
        coupText.setFillColor(sf::Color::Black);

        undoTaxButton.setSize(sf::Vector2f(90, 50));
        undoTaxButton.setPosition(20, 320);
        undoTaxButton.setFillColor(sf::Color::Green);
        undoTaxText.setFont(font);
        undoTaxText.setCharacterSize(16);
        undoTaxText.setString("UNDO TAX");
        undoTaxText.setPosition(25, 330);
        undoTaxText.setFillColor(sf::Color::Black);

        spyButton.setSize(sf::Vector2f(90, 50));
        spyButton.setPosition(20, 320);
        spyButton.setFillColor(sf::Color::Green);
        spyText.setFont(font);
        spyText.setCharacterSize(16);
        spyText.setString("SPY");
        spyText.setPosition(30, 330);
        spyText.setFillColor(sf::Color::Black);

        spyMessege.setFont(font);
        spyMessege.setCharacterSize(20);
        spyMessege.setPosition(20, 280);
        spyMessege.setFillColor(sf::Color::Yellow);

        investButton.setSize(sf::Vector2f(90, 50));
        investButton.setPosition(20, 320);
        investButton.setFillColor(sf::Color::Green);
        investText.setFont(font);
        investText.setCharacterSize(16);
        investText.setString("INVEST");
        investText.setPosition(30, 330);
        investText.setFillColor(sf::Color::Black);

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

                    Player* curr = game.getCurrentPlayer();
                    bool mustCoup = (curr != nullptr && ((GameRules*)curr)->mustCoup());

                    if (skipButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        if (curr != nullptr) {
                            ((GameRules*)curr)->skipTurn();
                        }
                    }

                    if (!mustCoup && gatherButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        if (curr != nullptr) {
                            ((GameRules*)curr)->gather();
                        }
                    }

                    if (!mustCoup && taxButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        if (curr != nullptr) {
                            ((GameRules*)curr)->tax();
                        }
                    }

                    if (!mustCoup && bribeButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        if (curr != nullptr) {
                            ((GameRules*)curr)->bribe();
                        }
                    }

                    if (!mustCoup && arrestButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        selectToArrest = true;
                        targetIndex = -1;
                    }

                    if (!mustCoup && selectToArrest && targetIndex >= 0 && targetIndex < game.getNumOfPlayers()) {
                        Player* target = game.getPlayerIndex(targetIndex);
                        if (curr != nullptr && target != curr && target->getCoins() > 0) {
                            ((GameRules*)curr)->arrest(*target);
                            targetIndex = -1;
                            selectToArrest = false;
                        }
                    }

                    if (!mustCoup && sanctionButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        selectToSanction = true;
                        targetIndex = -1;
                    }

                    if (!mustCoup && selectToSanction && targetIndex >= 0 && targetIndex < game.getNumOfPlayers()) {
                        Player* target = game.getPlayerIndex(targetIndex);
                        if (curr != nullptr && target != curr && !target->getSanctioned()) {
                            ((GameRules*)curr)->sanction(*target);
                            targetIndex = -1;
                            selectToSanction = false;
                        }
                    }

                    if (coupButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)) {
                        selectToCoup = true;
                        targetIndex = -1;
                    }

                    if (selectToCoup && targetIndex >= 0 && targetIndex < game.getNumOfPlayers()) {
                        Player* target = game.getPlayerIndex(targetIndex);
                        if (curr != nullptr && target != curr && curr->getCoins() >= 7 && !target->isCouped()) {
                            ((GameRules*)curr)->coup(*target);
                            delete target;
                            game.removePlayer(targetIndex);
                            targetIndex = -1;
                            selectToCoup = false;
                        }
                    }

                    if (undoTaxButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)){
                        if(curr != nullptr && curr->getRole() == "Governor"){
                            selectToUndoTax = true;
                            targetIndex = -1;
                        }
                    }
                    if (selectToUndoTax && targetIndex >= 0 && targetIndex < game.getNumOfPlayers()) {
                        Player* target = game.getPlayerIndex(targetIndex);
                        if (curr != nullptr && target != curr && curr->getRole() == "Governor" && target->getDidTax()) {
                            ((Governor*)curr)->taxBlock(*target);
                            selectToUndoTax = false;
                            targetIndex = -1;

                        }
                    }
                    if (spyButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)){
                        if (curr != nullptr && curr->getRole() == "Spy") {
                            selectToSpy = true;
                            targetIndex = -1;
                        }
                    }
                    if (selectToSpy && targetIndex >= 0 && targetIndex < game.getNumOfPlayers()) {
                        Player* target = game.getPlayerIndex(targetIndex);
                        if (curr != nullptr && target != curr && curr->getRole() == "Spy") {
                            int coins = ((Spy*)curr)->getCoins(*target);
                            spyMessege.setString("You spied on " + target->getName() + " and found out they have " + std::to_string(coins) + " coins.");
                            spyMessegeTimer.restart();
                            showSpyMessage = true;
                            ((Spy*)curr)->arrestBlock(*target);
                            selectToSpy = false;
                            targetIndex = -1;
                        }
                    }
                    if (investButton.getGlobalBounds().contains((float)mouseX, (float)mouseY)){
                        if (curr != nullptr && curr->getRole() == "Baron" && curr->getCoins() >= 3) {
                            Baron* baron = dynamic_cast<Baron*>(curr);
                            if (baron != nullptr) {
                                baron->invest();
                            }
                        }
                    }
                }
            }

            window.clear(sf::Color::Black);

            if (!gameStarted) {
                registration();
            } else {
                showButtons();
                showMessage();
  
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

    void Gui::showButtons() {
        Player* curr = game.getCurrentPlayer();
        bool mustCoup = (curr != nullptr && ((GameRules*)curr)->mustCoup());
        showCurrTurn();
        showPlayers();

        makeButton(skipButton, skipText);

        if (mustCoup || (curr != nullptr && curr->getSanctioned())) {
            gatherButton.setFillColor(sf::Color::Red);
            taxButton.setFillColor(sf::Color::Red);
        } else {
            gatherButton.setFillColor(sf::Color::Green);
            taxButton.setFillColor(sf::Color::Green);
        }

        if (mustCoup || curr == nullptr || curr->getCoins() <= 3) {
            bribeButton.setFillColor(sf::Color::Red);
        } else {
            bribeButton.setFillColor(sf::Color::Green);
        }

        if (mustCoup || curr == nullptr || curr->isSpied()) {
            arrestButton.setFillColor(sf::Color::Red);
        } else {
            arrestButton.setFillColor(sf::Color::Green);
            if (selectToArrest) playerSelect("arrest");
        }

        if (mustCoup || curr == nullptr || curr->getCoins() <= 2 || curr->getSanctioned()) {
            sanctionButton.setFillColor(sf::Color::Red);
        } else {
            sanctionButton.setFillColor(sf::Color::Green);
            if (selectToSanction) playerSelect("sanction");
        }

        if (curr != nullptr && curr->getCoins() >= 7) {
            coupButton.setFillColor(sf::Color::Green);
            if (selectToCoup) playerSelect("coup");
        } else {
            coupButton.setFillColor(sf::Color::Red);
        }

        if (curr != nullptr && curr->getRole() == "Governor") {
            makeButton(undoTaxButton, undoTaxText);
            if (selectToUndoTax){
                playerSelect("undo tax");
            }
        }

        if (curr != nullptr && curr->getRole() == "Spy") {
            Spy* spy = dynamic_cast<Spy*>(curr);
            if (spy != nullptr && !spy->getSpiedThisTurn()) {
                spyButton.setFillColor(sf::Color::Green);
            } else {
                spyButton.setFillColor(sf::Color::Red);
            }

            makeButton(spyButton, spyText);

            if (selectToSpy && spy != nullptr && !spy->getSpiedThisTurn()) {
                playerSelect("spy");
            }
        }

        if (curr != nullptr && curr->getRole() == "Baron") {
            makeButton(investButton, investText);
            if (curr->getCoins() >= 3) {
                investButton.setFillColor(sf::Color::Green);
            } else {
                investButton.setFillColor(sf::Color::Red);
            }
        }


        makeButton(gatherButton, gatherText);
        makeButton(taxButton, taxText);
        makeButton(bribeButton, bribeText);
        makeButton(arrestButton, arrestText);
        makeButton(sanctionButton, sanctionText);
        makeButton(coupButton, coupText);
    }

    void Gui::showMessage(){
        if (showSpyMessage && spyMessegeTimer.getElapsedTime().asSeconds() < 3) {
            window.draw(spyMessege);
        } else{
            showSpyMessage = false;
        }
        
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
            if (player->getExtraMove()){
                status += ": has extra move ";
            }
            if (player->isArrested()){
                status += ": got arrested ";
            }
            if (player->getSanctioned()){
                status += ": sanctioned ";
            }
            if (player->isSpied()){
                status += ": spied ";
            }
            if (player->getDidTax()){
                status += ": did tax ";
            }
            std::string line = player->getName() + "::     role: " + player->getRole() + " :amount of coins: " + std::to_string(player->getCoins()) + " " + status;
            sf::Text text(line, font, 20);
            text.setPosition(20,position);
            text.setFillColor(player == game.getCurrentPlayer() ? sf::Color::Green : sf::Color::Red);
            window.draw(text);
            position += 30;

            sf::FloatRect bounds = text.getGlobalBounds();
            int mx = sf::Mouse::getPosition(window).x;
            int my = sf::Mouse::getPosition(window).y;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (bounds.contains((float)mx, (float)my) &&
                    player != game.getCurrentPlayer()) {
                    targetIndex = i;
                }
            }
            if (i == targetIndex) {
                text.setFillColor(sf::Color::Magenta);
            }


        }
    }

    void Gui::playerSelect(const std::string& mode) {
        float position = 70;
        sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

        for (int i = 0; i < game.getNumOfPlayers(); ++i) {
            Player* player = game.getPlayerIndex(i);
            bool canBeSelected = (player != game.getCurrentPlayer());

            if (mode == "arrest") {
                canBeSelected = canBeSelected && !player->isArrested() && !player->getArrestedLastTurn() && player->getCoins() > 0;
            }
            else if (mode == "sanction") {
                canBeSelected = canBeSelected && !player->getSanctioned();
            } else if (mode == "coup") {
                canBeSelected = canBeSelected && !player->isCouped();
            }
            else if (mode == "undoTax"){
                canBeSelected = canBeSelected && player->getDidTax();
            }
            else if (mode == "spy") {
                canBeSelected = canBeSelected;
            }

            sf::Text text(player->getName(), font, 20);
            text.setPosition(20, position);
            sf::FloatRect bounds = text.getGlobalBounds();
            bool isSelected = bounds.contains(mousePos) && canBeSelected;
            if (isSelected){
                sf::RectangleShape highlight(sf::Vector2f(bounds.width, bounds.height));
                highlight.setPosition(text.getPosition());
                highlight.setFillColor(sf::Color(255, 255, 0, 100));
                window.draw(highlight);
            }
            if (i == targetIndex) {
                text.setFillColor(sf::Color::Magenta);
            } else if (!canBeSelected) {
                text.setFillColor(sf::Color(100, 100, 100));
            } else {
                text.setFillColor(sf::Color::Blue);
            }
            window.draw(text);

            if (isSelected && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                targetIndex = i;
            }
            position += 30;
        }
        sf::Text func("Select a player to " + mode, font, 20);
        func.setPosition(20, 20);
        func.setFillColor(sf::Color::Yellow);
        window.draw(func);
    }

}