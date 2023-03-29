#include "card.hpp"
#include "player.hpp"
#include <string>
using namespace std;
using namespace ariel;

Player:: Player(){ //defult constructor
    this->name = "player";
}
Player:: Player(string name){ //constructor with parameter of the name
    this->name = name;
}
string Player:: getName() const{
    return this->name;
}
int Player:: stacksize() const{
    return 0;
}
int Player:: cardesTaken() const{
    return 0;
}
string Player:: toString() const{
    return "";
}
