#include "card.hpp"
#include "player.hpp"
#include <string>
#include <list>
using namespace std;
using namespace ariel;

Player:: Player(){ //defult constructor
    this-> name = "player"; // defult name for an anonimus player.
    this-> taken = 0; // initialize counter for cards taken.
    this-> loseCounter = 0; // initialize counter for loses.
}
Player:: Player(string name){ //constructor with parameter of the name
    this->name = name; 
    this-> taken = 0; // initialize counter for cards taken.
    this-> loseCounter = 0; // initialize counter for loses.
}
string Player:: getName() const{ // returns the name of the player.
    return this->name;
}
int Player:: stacksize() const{ // returns the size of the list of the hand cards.
    return this-> cards.size();
}
int Player:: cardesTaken() const{ // retuns how many cards the player took.
    return this-> taken;
}
int Player:: throwCard(){ // throw a card from the hand and return it.
    int c = this-> cards.front(); // save the value of the card in the front of the packet.
    this-> cards.pop_front(); // delete the card from the front of the packet.
    return c; // return the value of the throwed card.
}
void Player:: take(int amount){ // get a number of cards taken and add it to the cards taken counter.
    this-> taken += amount;
}
void Player:: lose(){ // function to promote the lose counter.
    this-> loseCounter += 1;
}
void Player:: pushToHand(int card){ // function to add a card to the hand.
    this-> cards.push_front(card);
}
void Player:: winCard(int card){ // function to add a card that won a turn to the list of win cards.
    this-> cardsWon.push_back(card);
}
void Player:: printCards(){ // prints all the cards from the hand.
    for (auto i : this-> cards) {
        cout<< Card(i).toString() <<endl;
    }
}
string Player:: states() const{ // return the stats of the player
    int wins= this-> cardsWon.size(); // the amount of the wins of the player.
    float rate = (float)wins/ (float)(this-> loseCounter+wins); // the ratio of wins to all turns.
    string str = this->name + " States:\n"; // the string to return.
    str += "Cards taken: " + to_string(this-> cardesTaken()); // the amount of the cards taken.
    str += "\nWins: "+ to_string(wins); // the amount of the cards wins.
    str += "\nLoses: "+ to_string(this-> loseCounter); // the amount of the cards loses.
    str += "\nWin rate: "+ to_string((int)(rate*100))+"%"; // the precent of the wins to all turns.
    str += "\nCards won:\n"; // all the cards that won a turn for the player.
    for (auto i : this-> cardsWon) {
        str += "\t"+Card(i).toString() +'\n';
    }
    return str;
}
