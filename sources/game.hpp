#pragma once
#include <iostream>
#include "player.hpp"
using namespace std;

namespace ariel
{
    class Game{
        private:
        Player player1, player2;

        public:
        Game(); //defult Constructor
        Game(Player p1, Player p2); //constructor with 2 parameters
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}
