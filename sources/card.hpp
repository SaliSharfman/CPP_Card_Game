#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Card{
        private:
        int number;
        int color;

        public:
        Card(int n);
        Card(int number, int color);
        int getNumber() const;
        int getSerialNum() const; 
        int getColor() const;
        string toString() const;
    };
}