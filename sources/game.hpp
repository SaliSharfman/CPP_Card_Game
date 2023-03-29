#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Game{
        private:
        Player player1, player2;

        public:
        Game();
        Game(Player p1, Player p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}