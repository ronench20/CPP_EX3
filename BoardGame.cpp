//ronen.chereshn@msmail.ariel.ac.il

#include "BoardGame.hpp"
#include <cstdlib>
#include "RolesH/Baron.hpp"
#include "RolesH/General.hpp"
#include "RolesH/Governor.hpp"
#include "RolesH/Judge.hpp"
#include "RolesH/Merchant.hpp"
#include "RolesH/Spy.hpp"

using namespace std;

namespace player {
    BoardGame::BoardGame() {
        srand((unsigned int)(time(0)));
        for (int i = 0; i < 6; i++) {
            playersList[i] = nullptr;
        }
    }

    void BoardGame::addPlayer(Player *player) {
        if (numOfPlayers < 6) {
            playersList[numOfPlayers++] = player;
        } else {
            std::cout << "Cannot add more players." << std::endl;
        }
    }

    string BoardGame::turn() const {
        if (numOfPlayers < 2) {
            return "No players in the game.";
        } else{
            return playersList[currentPlayerIndex]->getName();
        }
    }

    Player* BoardGame::getCurrentPlayer() const {
        if (numOfPlayers < 2) {
            return nullptr;
        } else {
            return playersList[currentPlayerIndex];
        }
    }
    int BoardGame::getNumOfPlayers() const {
        return numOfPlayers;
    }

    Player* BoardGame::getPlayerIndex(int index) const {
        if (index < 0 || index >= numOfPlayers) {
            return nullptr;
        }
        return playersList[index];
    }

    int BoardGame::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
    }


    string BoardGame::players() const {
        string names;
        for (int i = 0; i < numOfPlayers; i++) {
            names += playersList[i]->getName();
            if (i < numOfPlayers - 1) {
                names += ", ";
            }
        }
        return names;
    }

    string BoardGame::winner() const {
        int count = 0;
        string winnerName;
        for (int i = 0; i < numOfPlayers; ++i) {
            if (!playersList[i]->isCouped()) {
                count++;
                winnerName = playersList[i]->getName();
            }
        }
        if (count == 1) {
            return winnerName;
        } else {
            return "No winner yet.";
        }
    }

    void BoardGame::nextTurn() {
        Player* current = getCurrentPlayer();
        if (current != nullptr && current->getExtraMove()) {
            current->setExtraMove(false);
            std::cout << current->getName() << " used their extra action (bribe).\n";
            return;
        }

        if (numOfPlayers < 2) {
            cout << "No players in the game." << endl;
        } else {
            for (int i = 0; i < numOfPlayers; ++i) {
                int next = (currentPlayerIndex + 1) % numOfPlayers;
                if (!playersList[next]->isCouped()) {
                    currentPlayerIndex = next;
                    getCurrentPlayer()->startTurn();
                    return;
                }
            }
        }
        if (current != nullptr && current->getRole() == "Spy")
        {
            Spy* spy = dynamic_cast<Spy*>(current);
            if (spy){
                spy->resetSpiedThisTurn();
            }
        }
        
    }

    void BoardGame::createPlayer(const string &name) {
        int i = rand() % 6;
        Player* player1 = nullptr;

        if (i == 0){
            player1 = new Baron(name, this);
        } else if (i == 1){
            player1 = new General(name, this);
        }
        else if (i == 2){
            player1 = new Governor(name, this);
        }
        else if (i == 3){
            player1 = new Judge(name, this);
        }
        else if (i == 4){
            player1 = new Merchant(name, this);
        }
        else if (i == 5){
            player1 = new Spy(name, this);
        }
        addPlayer(player1);
        cout << "player added" << endl;
    }

    void BoardGame::removePlayer(int index) {
        if (index < 0 || index >= numOfPlayers){
            return;
        }
        for (int i = index; i < numOfPlayers - 1; ++i) {
            playersList[i] = playersList[i + 1];
        }
        playersList[numOfPlayers - 1] = nullptr;
        numOfPlayers--;
        if (currentPlayerIndex >= numOfPlayers) {
            currentPlayerIndex = 0;
        }
    }

    bool BoardGame::getAwaitingCoup() const {
        return awaitingCoup;
    }

    int BoardGame::getCurrGeneralIndex() const {
        return generals[nextGeneralIndex];
    }

    bool BoardGame::canGeneralPreventCoup() const {
        int i =generals[nextGeneralIndex];
        return playersList[i]->getCoins() >= 5;
    }

    void BoardGame::coupApproval(int attackerIndex, int targetIndex) {
        awaitingCoup = true;
        this->attackerIndex = attackerIndex;
        this->targetIndex = targetIndex;
        numOfGenerals = 0;

        for (int i = 0; i < numOfPlayers; ++i) {
            if (playersList[i]->getRole() == "General" && !playersList[i]->isCouped()) {
                generals[numOfGenerals++] = i;
            }
        }

        nextGeneralIndex = 0;
        if (numOfGenerals == 0){
            GameRules* attacker = dynamic_cast<GameRules*>(playersList[attackerIndex]);
            attacker->coup(*playersList[targetIndex]);
            clearApproval();
        }
    }

    void BoardGame::coupDecision(bool prevent){
        if (!awaitingCoup) {
            cout << "No coup in progress." << endl;
            return;
        }
        Player* attacker = playersList[attackerIndex];

        if (prevent) {
            Player* general = playersList[generals[nextGeneralIndex]];
            if (general->getCoins() >= 5){
                general->removeCoins(5);
                attacker->removeCoins(7);
                nextTurn();
                clearApproval();
            }else{
                cout << "General " << general->getName() << " doesn't have enough coins to prevent." << endl;
            }

        } else {
            ++nextGeneralIndex;
            if (nextGeneralIndex >= numOfGenerals) {
                if (attacker->getCoins() >= 7) {
                    Player* target = playersList[targetIndex];
                    target->setCouped(true);
                    attacker->removeCoins(7);
                    delete target;
                    removePlayer(targetIndex);
                    nextTurn();
                } else {
                    cout << "Attacker doesn't have enough coins!" << endl;
                }
                clearApproval();
            } else {
                Player* general = playersList[generals[nextGeneralIndex]];
                cout << "General " << general->getName() << " can prevent the coup." << endl;
            }
        } 
    }

    void BoardGame::clearApproval() {
        awaitingCoup = false;
        attackerIndex = -1;
        targetIndex = -1;
        numOfGenerals = 0;
        nextGeneralIndex = 0;
    }

    bool BoardGame::getAwaitingBribe() const {
        return awaitingBribe;
    }

    int BoardGame::getCurrJudgeIndex() const {
        return judges[nextJudgeIndex];
    }

    void BoardGame::bribeApproval(int bribeIndex){
        awaitingBribe = true;
        this->briberIndex = bribeIndex;
        numOfJudges = 0;

        for (int i = 0; i < numOfPlayers; ++i) {
            if (playersList[i]->getRole() == "Judge" && !playersList[i]->isCouped()) {
                judges[numOfJudges++] = i;
            }
        }

        nextJudgeIndex = 0;
        if (numOfJudges == 0)
        {
            clearBribeApproval();
        }
        
    }

    void BoardGame::bribeDecision(bool prevent){
        if (!awaitingBribe) {
            cout << "No bribe in progress." << endl;
            return;
        }
        Player* briber = playersList[briberIndex];
        Player* judge = playersList[judges[nextJudgeIndex]];

        if (prevent) {
            Judge* judgePlayer = dynamic_cast<Judge*>(judge);
            GameRules* rules = dynamic_cast<GameRules*>(briber);
            if (judgePlayer != nullptr && rules != nullptr){
                judgePlayer->blockBribe(*briber);
                rules->setBribeBlocked(true);
            }
            clearBribeApproval();
            return;
        }
        nextJudgeIndex++;
        if (nextJudgeIndex >= numOfJudges){
            clearBribeApproval();
        }
          

    }
    void BoardGame::clearBribeApproval() {
        awaitingBribe = false;
        briberIndex = -1;
        targetJudgeIndex = -1;
        numOfJudges = 0;
        nextJudgeIndex = 0;
    }

}