#include "card.hpp"
#include "player.hpp"
#include <string>
#include <list>
using namespace std;
using namespace ariel;

Player:: Player(){ //defult constructor
    this-> name = "player";
    this-> taken = 0;
    this-> loseCounter = 0;
}
Player:: Player(string name){ //constructor with parameter of the name
    this->name = name;
    this-> taken = 0;
    this-> loseCounter = 0;
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
void Player:: lose(){
    this-> loseCounter += 1;
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
    int wins= this-> cardsWon.size();
    float rate = (float)wins/ (float)(this-> loseCounter+wins);
    string str = this->name + " States:\n";
    str += "Cards taken: " + to_string(this-> cardesTaken());
    str += "\nWins: "+ to_string(wins);
    str += "\nLoses: "+ to_string(this-> loseCounter);
    str += "\nWin rate: "+ to_string((int)(rate*100))+"%";
    str += "\nCards won:\n";
    for (auto i : this-> cardsWon) {
        str += "\t"+Card(i).toString() +'\n';
    }
    return str;
}
