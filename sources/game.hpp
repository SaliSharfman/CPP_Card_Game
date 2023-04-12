#pragma once
#include <iostream>
#include "player.hpp"
#include <list>
using namespace std;

namespace ariel
{
    class Game{
        private:
        Player& player1;
        Player& player2;
        list<string> log{};
        int drawCounter, turnsCounter;

        public:
        Game(Player& p1, Player& p2); //constructor with 2 parameters
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void dealCards();
        bool isFinished();
    };
}
