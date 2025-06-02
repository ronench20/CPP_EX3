//ronen.chereshn@msmail.ariel.ac.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Player.hpp"
#include "../BoardGame.hpp"
#include "../RolesH/Baron.hpp"
#include "../RolesH/Governor.hpp"
#include "../RolesH/Judge.hpp"
#include "../RolesH/Merchant.hpp"
#include "../RolesH/Spy.hpp"
#include "../RolesH/General.hpp"
#include "../GameRules.hpp"
//#include "../display/Gui.hpp"

using namespace player;

TEST_CASE("Player tests")
{
    BoardGame board;
    Judge judge("Ronen", &board);
    SUBCASE("constructor tests") {
        CHECK(judge.getName() == "Ronen");
        CHECK(judge.getRole() == "Judge");
        CHECK(judge.getCoins() == 0);
        CHECK_FALSE(judge.isArrested());
        CHECK_FALSE(judge.getArrestedLastTurn());
        CHECK_FALSE(judge.getSanctioned());
        CHECK_FALSE(judge.getSanctionedUntilNextTurn());
        CHECK_FALSE(judge.isCouped());
        CHECK_FALSE(judge.getDidTax());
        CHECK_FALSE(judge.isSpied());}

    SUBCASE("Basic tests")
    {
        CHECK_THROWS_AS(judge.setRole("Baron"), std::invalid_argument);
        judge.addCoins(2);
        CHECK(judge.getCoins() == 2);
        judge.removeCoins(1);
        CHECK(judge.getCoins() == 1);
        CHECK_THROWS_AS(judge.removeCoins(2), std::invalid_argument);
        judge.setArrested(true);
        CHECK(judge.isArrested());
        judge.setArrestedLastTurn(true);
        CHECK(judge.getArrestedLastTurn());
        judge.setSanctioned(true);
        CHECK(judge.getSanctioned());
        judge.setSanctionedUntilNextTurn(true);
        CHECK(judge.getSanctionedUntilNextTurn());
        judge.setDidTax(true);
        CHECK(judge.getDidTax());
        judge.setCouped(true);
        CHECK(judge.isCouped());
        judge.setSpied(true);
        CHECK(judge.isSpied());
    }
}

TEST_CASE("GameRules"){
    BoardGame boardGame;
    Judge judge("judge", &boardGame);
    Governor governor("governor", &boardGame);
    judge.startTurn();
    CHECK_FALSE(judge.getSanctioned());
    judge.gather();
    CHECK(judge.getCoins() == 1);
    judge.tax();
    CHECK(judge.getCoins() == 3);
    judge.setSanctioned(true);
    CHECK(judge.getSanctioned() == true);
    CHECK_THROWS(judge.gather(), "You can't gather because you are under sanction.");
    CHECK_THROWS(judge.tax(), "You can't tax because you are under sanction.");
    judge.addCoins(2);
    governor.addCoins(10);
    governor.bribe();
    judge.removeCoins(1);
    CHECK_FALSE(judge.getBribeBlocked());
    judge.arrest(governor);
    CHECK(governor.isArrested());
    CHECK(judge.getCoins() == 5);
    CHECK(governor.getCoins() == 5);
    governor.setArrested(false);
    governor.setArrestedLastTurn(false);
}

TEST_CASE("BoardGame tests")
{
    BoardGame boardGame;
    boardGame.createPlayer("Player1");
    CHECK(boardGame.winner() == "Player1");


    boardGame.createPlayer("Player2");
    boardGame.createPlayer("Player3");
    boardGame.createPlayer("Player4");
    boardGame.createPlayer("Player5");
    boardGame.createPlayer("Player6");

    CHECK_THROWS(boardGame.winner(), "No winner yet.");


    CHECK(boardGame.getNumOfPlayers() == 6);
    CHECK(boardGame.getCurrentPlayerIndex() == 0);

    Player* current = boardGame.getCurrentPlayer();
    CHECK(current->getName() == "Player1");


    boardGame.nextTurn();
    current = boardGame.getCurrentPlayer();
    CHECK(current->getName() == "Player2");
    CHECK(boardGame.getCurrentPlayerIndex() == 1);
    CHECK(boardGame.turn() == "Player2");

    boardGame.removePlayer(0);
    CHECK(boardGame.getNumOfPlayers() == 5);

    for (int i = 0; i < 3; ++i) {
        boardGame.nextTurn();
    }

    current = boardGame.getCurrentPlayer();
    CHECK(current->getName() == "Player6");

    for (int i = 0; i < 3; ++i) {
        boardGame.nextTurn();
    }

    std::string players = boardGame.players();
    CHECK(players == "Player2, Player3, Player4, Player5, Player6");

}

TEST_CASE("Rules")
{
    BoardGame board;
    Governor target("target", &board);
    target.addCoins(8);

    SUBCASE("Governor")
    {
        Governor governor("governor", &board);
        governor.tax();
        CHECK(governor.getCoins() == 3);
    }

    SUBCASE("Spy"){
        Spy spy("spy", &board);
        CHECK(spy.getCoins(target) == 8);
        spy.arrestBlock(target);
        CHECK(target.isSpied());
        CHECK_THROWS(spy.arrestBlock(target), "You have already spied this turn.");
    }

    SUBCASE("Baron"){
        Baron baron("baron", &board);
        CHECK_THROWS(baron.invest(), "Not enough coins to invest.");
        baron.addCoins(3);
        baron.invest();
        CHECK(baron.getCoins() == 6);
        target.sanction(baron);
        CHECK(baron.getSanctioned());
        CHECK(baron.getCoins() == 7);
    }

    SUBCASE("General"){
        General general("general", &board);
        general.addCoins(2);
        target.arrest(general);
        CHECK(general.isArrested());
        CHECK(general.getCoins() == 2);
        CHECK(target.getCoins() == 9);
    }

    SUBCASE("Judge")
    {
        Judge judge("judge", &board);
        judge.addCoins(4);
        target.setExtraMove(true);
        judge.blockBribe(target);
        CHECK(target.getExtraMove() == false);
        CHECK(judge.getCoins() == 0);
    }

    SUBCASE("Merchant")
    {
        Merchant merchant ("merchant", &board);
        merchant.addCoins(3);
        target.arrest(merchant);
        CHECK(merchant.isArrested());
        CHECK(merchant.getCoins() == 1);
        CHECK(target.getCoins() == 8);
    }

}
