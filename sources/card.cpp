#include "card.hpp"
using namespace std;
using namespace ariel;

Card:: Card(int number, int color){ //constructor that gets 2 int parameters for the number and color of the card
    this->number = number;
    this->color = color;
}
int Card:: getNumber() const{
    return this->number;
}
int Card:: getColor() const{
    return this->color;
}
string Card:: toString() const{
    return "";
}
