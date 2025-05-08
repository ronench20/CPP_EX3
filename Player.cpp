//
// Created by ronen on 07/05/2025.
//

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

//    void Player::gather() {
//        if (!isSanctioned()) {
//            coins++;
//        }
//    }
//
//    void Player::tax() {
//        if (!isSanctioned()) {// change to the right function
//            coins += 2;
//        }
//    }
//
//    void Player::bribe() {
//        if (coins >= 4) {
//            coins -= 4;
//        } else {
//            std::cout << "Not enough coins to bribe." << std::endl;
//        }
//    }
//
//    void Player::arrest(Player &target) {
//        if (target.isArrested()){
//            std::cout << target.getName() << " is already arrested." << std::endl;
//        }
//        else if (target.getCoins() == 0) {
//            std::cout << target.getName() << " has no coins to arrest." << std::endl;
//        }
//        else {
//            target.setArrested(true);
//            target.removeCoins(1);
//            coins++;
//        }
//    }

    bool Player::isArrested() const {
        return arrested;
    }

    void Player::setArrested(bool arrested) {
        this->arrested = arrested;
    }

//    void Player::sanction(Player &target) {
//        if (coins >= 3) {
//            coins -= 3;
//            target.setSanctioned(true);
//        } else {
//            std::cout << "Not enough coins to sanction." << std::endl;
//        }
//    }

    bool Player::isSanctioned() const {
        return sanctioned;
    }

    void Player::setSanctioned(bool sanctioned) {
        this->sanctioned = sanctioned;
    }

//    void Player ::coup(Player &target) {
//        if (coins >= 7) {
//            coins -= 7;
//            target.setCouped(true);
//        } else {
//            std::cout << "Not enough coins to coup." << std::endl;
//        }
//    }

    bool Player::isCouped() const {
        return couped;
    }

    void Player::setCouped(bool couped) {
        this->couped = couped;
    }
}