//ronen.chereshn@msmail.ariel.ac.il

#include "Player.hpp"
#include <stdexcept>
#include <iostream>

namespace player {
    Player::Player(std::string name){
        this->name = name;
        this->role = "default";
        this->coins = 0;
        this->arrested = false;
        this->arrestedLastTurn = false;
        this->sanctioned = false;
        this->sanctionedUntilNextTurn = false;
        this->couped = false;
        this->didTax = false;
        this->spied = false;
        this->spiedUntilNextTurn = false;
        this->extraMove = false;
    }

    std::string Player::getName() const {
        return name;
    }
    std::string Player::getRole() const {
        return role;
    }

    void Player::setRole(std::string roleName) {
        if (this->role == "default") {
            this->role = roleName;
        }
        else{
            throw std:: invalid_argument("Role already set.");
        }
    }

    int Player::getCoins() const {
        return coins;
    }

    void Player::addCoins(int amount) {
        coins += amount;
        std:: cout << "coin added" << std::endl;

    }

    void Player::removeCoins(int amount) {
        coins -= amount;
    }


    bool Player::isArrested() const {
        return arrested;
    }

    void Player::setArrested(bool value) {
        this->arrested = value;
    }

    void Player::setArrestedLastTurn(bool value) {
        arrestedLastTurn = value;
    }

    bool Player::getArrestedLastTurn() const {
        return arrestedLastTurn;
    }


    bool Player::getSanctioned() const {
        return sanctioned;
    }

    void Player::setSanctioned(bool value) {
        this->sanctioned = value;
    }


    bool Player::getSanctionedUntilNextTurn() const {
        return sanctionedUntilNextTurn;
    }

    void Player::setSanctionedUntilNextTurn(bool value) {
        sanctionedUntilNextTurn = value;
    }

    bool Player::isCouped() const {
        return couped;
    }

    void Player::setDidTax(bool value) {
        didTax = value;
    }

    bool Player::getDidTax() const {
        return didTax;
    }

    void Player::setCouped(bool value) {
        this->couped = value;
    }


    bool Player::isSpied() const {
        return spied;
    }
    void Player::setSpied(bool value) {
        this->spied = value;
    }
    void Player::setSpiedUntilNextTurn(bool value) {
        spiedUntilNextTurn = value;
    }

    void Player::startTurn() {
        didTax = false;

        if (spiedUntilNextTurn) {
            spiedUntilNextTurn = false;
        }
        else if (spied) {
            spied = false;
            std::cout << getName() << "'s spy block has expired." << std::endl;
        }

        if (arrestedLastTurn) {
            arrestedLastTurn = false;
        }
        else if (arrested) {
            setArrested(false);
            std::cout << getName() << " is no longer arrested.\n";
        }

        if (sanctionedUntilNextTurn){
            sanctionedUntilNextTurn = false;
        }
        else if (sanctioned) {
            setSanctioned(false);
            std::cout << getName() << "'s sanction expired at the start of the turn.\n";
        }
    }
    void Player::setExtraMove(bool value) {
        extraMove = value;
    }
    bool Player::getExtraMove() const {
        return extraMove;
    }
}