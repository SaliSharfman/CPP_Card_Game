#include "card.hpp"
using namespace std;
using namespace ariel;

Card:: Card(int number, int color){ //constructor that gets 2 int parameters for the number and color of the card
    this->number = number;
    this->color = color;
}
Card:: Card(int n){ //constructor that gets 1 int parameter that presents a uniqe card.
    this->number = n/4+1;
    this->color = n%4;
}
int Card:: getNumber() const{ // returns the number of the card
    return this->number;
}
int Card:: getColor() const{ // returns the color of the card
    return this->color;
}
int Card:: getSerialNum() const{ // returns the serial number of the card (0 to 51)
    return (this->number-1) *4 + this->color;
}
string Card:: toString() const{
    string num= to_string(this->number);
    string sign= "";
    switch (this->number){
        case 1:
        num = "Ace";
        break;
        case 11:
        num = "Jack";
        break;
        case 12:
        num = "Queen";
        break;
        case 13:
        num = "King";
        break;
    }
    switch (this->color){
        case 0:
        sign = "Spades";
        break;
        case 1:
        sign = "Hearts";
        break;
        case 2:
        sign = "Diamonds";
        break;
        case 3:
        sign = "Clubs";
        break;
    }
    return num + " of " + sign;
}
