#include "card.hpp"
using namespace std;
using namespace ariel;

Card:: Card(int number, int color){ //constructor that gets 2 int parameters for the number and color of the card.
    this->number = number;
    this->color = color;
}
Card:: Card(int n){ //constructor that gets 1 int parameter that presents a uniqe card.
    this->number = n/4+2;
    this->color = n%4;
}
int Card:: getNumber() const{ // returns the number of the card (2 to 14).
    return this->number;
}
int Card:: getColor() const{ // returns the color of the card (0 to 3).
    return this->color;
}
int Card:: getSerialNum() const{ // returns the serial number of the card (0 to 51).
    return (this->number-2) *4 + this->color;
}
string Card:: toString() const{ // return a string represents the card using the number and the color (for example "Ace of Spades", "5 of Hearts").
    string num= to_string(this->number); // the defult string of a number is the same number (2,3,4..10).
    string sign= "";
    switch (this->number){ // the special numbers (10,11,12,13,14).
        case 11:
        num = "Jack";
        break;
        case 12:
        num = "Queen";
        break;
        case 13:
        num = "King";
        break;
        case 14:
        num = "Ace";
        break;
    }
    switch (this->color){ // the number of the color will be a sign of a card.
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
