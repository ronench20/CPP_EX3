//ronen.chereshn@msmail.ariel.ac.il

#include "Player.hpp"

namespace player {
    int Player::getCoins() const {
        return coins;
    }

    void Player::addCoins(int amount) {
        coins += amount;
    }

    void Player::removeCoins(int amount) {
        coins -= amount;
    }


    bool Player::isArrested() const {
        return arrested;
    }

    void Player::setArrested(bool arrested) {
        this->arrested = arrested;
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

    void Player::setCouped(bool couped) {
        this->couped = couped;
    }

    bool Player::isGoverned() const {
        return governed;
    }

    void Player::setGoverned(bool governed) {
        this->governed = governed;
    }

    bool Player::isSpied() const {
        return spied;
    }
    void Player::setSpied(bool spied) {
        this->spied = spied;
    }

    void Player::startTurn() {
        arrestedLastTurn = false;
        if (sanctionedUntilNextTurn){
            sanctionedUntilNextTurn = false;
        }
        if (sanctioned && !sanctionedUntilNextTurn) {
            setSanctioned(false);
            std::cout << getName() << "'s sanction expired at the start of the turn.\n";
        }
    }
}