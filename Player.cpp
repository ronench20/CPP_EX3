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


    bool Player::isSanctioned() const {
        return sanctioned;
    }

    void Player::setSanctioned(bool sanctioned) {
        this->sanctioned = sanctioned;
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
}