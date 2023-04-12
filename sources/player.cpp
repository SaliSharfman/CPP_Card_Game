#include "card.hpp"
#include "player.hpp"
#include <string>
#include <list>
using namespace std;
using namespace ariel;

Player:: Player(){ //defult constructor
    this-> name = "player";
    this-> taken = 0;
}
Player:: Player(string name){ //constructor with parameter of the name
    this->name = name;
    this-> taken = 0;
}
string Player:: getName() const{
    return this->name;
}
int Player:: stacksize() const{
    return this-> cards.size();
}
int Player:: cardesTaken() const{
    return this-> taken;
}
int Player:: throwCard(){
    int c = this-> cards.front();
    this-> cards.pop_front();
    return c;
}
void Player:: take(int amount){
    this-> taken += amount;
}
void Player:: pushToHand(int card){
    this-> cards.push_front(card);
}
void Player:: winCard(int card){
    this-> cardsWon.push_back(card);
}
void Player:: printCards(){
    for (auto i : this-> cards) {
        cout<< Card(i).toString() <<endl;
    }
}
string Player:: states() const{
    string str = this->name + " states:\nCards Taken: " + to_string(this-> cardesTaken()) +"\nWins: "+ to_string(this-> cardsWon.size())+ "\nCards Won:\n";
    for (auto i : this-> cardsWon) {
        str += Card(i).toString() +'\n';
    }
    return str;
}
