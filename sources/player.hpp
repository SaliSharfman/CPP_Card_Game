#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Player{
        private:
        string name;

        public:
        Player();
        Player(string name);
        int stacksize() const;
        int cardesTaken() const;
        string toString() const;
    };
}