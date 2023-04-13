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
        list<int> cards{}; // initialise a list of integers for the cards in the hand of the player.
        list<int> cardsWon{}; // initialise a list of integers for the cards that won a turn for the player.

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
