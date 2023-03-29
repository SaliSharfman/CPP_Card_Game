#include "doctest.h"

#include <iostream>
#include <string>
using namespace std;

#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"
using namespace ariel;

TEST_CASE("card_tests")
{
    Card card1(12,1);
    CHECK_NOTHROW(card1.getNumber());
    CHECK_NOTHROW(card1.getColor());
    CHECK_NOTHROW(card1.toString());
    CHECK(card1.getNumber()==12);
    CHECK(card1.getColor()==1);
    CHECK(card1.toString()=="");

}
TEST_CASE("player_tests")
{
    Player player1("sali");
    CHECK_NOTHROW(player1.getName());
    CHECK_NOTHROW(player1.stacksize());
    CHECK_NOTHROW(player1.cardesTaken());
    CHECK_NOTHROW(player1.toString());
    CHECK(player1.getName() == "sali");
    CHECK(player1.toString() == "");
}
TEST_CASE("game_tests")
{
    Player player1("sali");
    Player player2("enemy");
    Game game1(player1,player2);
    CHECK(player1.getName() == "sali");
    CHECK(player2.getName() == "enemy");
    CHECK_NOTHROW(game1.playTurn());
    CHECK_NOTHROW(game1.printLastTurn());
    CHECK_NOTHROW(game1.playAll());
    CHECK_NOTHROW(game1.printWiner());
    CHECK_NOTHROW(game1.printLog());
    CHECK_NOTHROW(game1.printStats());
}