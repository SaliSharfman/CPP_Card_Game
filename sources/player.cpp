#include "card.hpp"
#include "player.hpp"
using namespace std;
using namespace ariel;

Player:: Player(){
    this->name = "player";
}
Player:: Player(string name){
    this->name = name;
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