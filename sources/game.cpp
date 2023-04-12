#include "card.hpp"
#include "player.hpp"
#include "game.hpp"
using namespace std;
using namespace ariel;
Game:: Game(Player& p1, Player& p2) : player1(p1), player2(p2){
    this-> drawCounter = 0;
    this-> turnsCounter = 0;
    this-> dealCards();
}
void Game:: dealCards(){
    srand(time(NULL));
    bool packet[52] = {false};
    for(int i =0; i<26; i++){
        int rnd = rand()%52;
        while(packet[rnd]){
            rnd = rand()%52;
        }
        this->player1.pushToHand(rnd);
        packet[rnd] = true;

        rnd = rand()%52;
        while(packet[rnd]){
            rnd = rand()%52;
        }
        this->player2.pushToHand(rnd);
        packet[rnd] = true;
    }

}
bool Game:: isFinished(){
    if(this->player1.stacksize()>0 && this->player2.stacksize()>0){
        return false;
    }
    return true;
}
void Game:: playTurn(){
    if(this->isFinished()){
        throw invalid_argument("The Game has finished.");
        return;
    }
     if (&player1 == &player2) {
        throw invalid_argument("Both of the players are the same player.");
    }
    string turnLog="";
    int cardsOnTable = 0, v1=0, v2=0;
    while(!this->isFinished() && v1 == v2){
        Card c1(this->player1.throwCard());
        turnLog += player1.getName() + " played " +c1.toString()+" ";
        Card c2(this->player2.throwCard());
        turnLog+=player2.getName()+" played " +c2.toString()+". ";
        cardsOnTable += 2;
        v1 = c1.getNumber();
        v2 = c2.getNumber();
        if(v1 == v2){
            turnLog += "Draw. ";
            this-> drawCounter +=1;
            this-> turnsCounter +=1;
            if(!this->isFinished()){
                Card c1(this->player1.throwCard()); // flipped card.
                Card c2(this->player2.throwCard());  // flipped card.
                cardsOnTable += 2;
            }
            if(this->isFinished()){
                this-> player1.take(cardsOnTable/2);
                this-> player2.take(cardsOnTable/2);
            }

        }
        else if(v1 >v2){
            this-> player1.take(cardsOnTable);
            this-> player1.winCard(c1.getSerialNum());
            turnLog += this-> player1.getName()+" wins.";
            this-> player2.lose();
            this-> turnsCounter +=1 ; 
        }
        else{
            this-> player2.take(cardsOnTable);
            this-> player2.winCard(c2.getSerialNum());
            turnLog += this-> player2.getName()+" wins.";
            this-> player1.lose();
            this-> turnsCounter +=1 ;
        }
    }
    this-> log.push_back(turnLog);

}
void Game:: printLastTurn(){
    cout << this->log.front() << endl;
}
void Game:: playAll(){
    while(!this->isFinished())
        this-> playTurn();
}
void Game:: printWiner(){
    int t1 = this-> player1.cardesTaken(), t2 = this-> player2.cardesTaken();
    if(t1>t2)
        cout << this->player1.getName() << endl;
    else if(t2>t1)
        cout << this->player2.getName() << endl;
    else
        cout << "Draw." << endl;
}
void Game:: printLog(){
    for (auto i : this-> log) {
        cout << i << endl;
    }
}
void Game:: printStats(){
    cout << ""<< endl;
    cout << "Game States:" << endl;
    cout << "Amount of draws: " + to_string(this->drawCounter)<< endl;
    cout << "Amount of turns: " + to_string(this->turnsCounter)<< endl;
    float rate = (float)this->drawCounter/ (float)this->turnsCounter;
    cout << "Draw rate: " + to_string((int)(rate*100))+"%\n"<< endl;
    cout << this-> player1.states() << endl;
    cout << this-> player2.states() << endl;
}

