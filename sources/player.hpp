#pragma once
#include <iostream>
#include <list>
using namespace std;

namespace ariel
{
    class Player{
        private:
        string name;
        int taken, loseCounter;
        list<int> cards{};
        list<int> cardsWon{};

        public:
        Player();
        Player(string name);
        string getName() const;
        int stacksize() const;
        int cardesTaken() const;
        void lose();
        void take(int amount);
        int throwCard();
        void pushToHand(int card);
        void printCards();
        void winCard(int card);
        string states() const;
    };
}