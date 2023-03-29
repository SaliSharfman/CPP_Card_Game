#include "card.hpp"
#include "player.hpp"
#include "game.hpp"
using namespace std;
using namespace ariel;
Game:: Game(){
    this->player1 = Player();
    this->player2 = Player();
}
Game:: Game(Player p1, Player p2){
    this->player1 = p1;
    this->player2 = p2;
}
void Game:: playTurn(){
}
void Game:: printLastTurn(){
}
void Game:: playAll(){
}
void Game:: printWiner(){
}
void Game:: printLog(){
}
void Game:: printStats(){
}
