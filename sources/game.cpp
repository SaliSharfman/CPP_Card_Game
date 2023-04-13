#include "card.hpp"
#include "player.hpp"
#include "game.hpp"
using namespace std;
using namespace ariel;
Game:: Game(Player& p1, Player& p2) : player1(p1), player2(p2){ // constructor with two parameters using reference of the players
    this-> drawCounter = 0; // initialize a counter for counting draws.
    this-> turnsCounter = 0; // initialize a counter for counting turns.
    this-> dealCards(); // calling to the "dealCards" function that deal a mixed packet of cards to the players equaly.
}
void Game:: dealCards(){ // a function that deal a mixed packet of cards to the players equaly.
    srand(time(NULL)); // initialize the random using time.
    bool packet[52] = {false}; // initalize a flags array in size of 52 false values for checking if a card is already dealed.
    for(int i =0; i<26; i++){ // loop of 26 times, every iteration deals one card to each player, in the end every player will have 26 cards.
        int rnd = rand()%52; // get random nuber between 0 to 51 represents a card.
        while(packet[rnd]){ // if the card has already dealed random again.
            rnd = rand()%52;
        }
        this->player1.pushToHand(rnd); // push the chosen card to the hand of player1  
        packet[rnd] = true; // mark the card as chosen.

        rnd = rand()%52; // repeat the same actions for player2
        while(packet[rnd]){
            rnd = rand()%52;
        }
        this->player2.pushToHand(rnd);
        packet[rnd] = true;
    }

}
bool Game:: isFinished(){ // function that checks if the game has finished.
    if(this->player1.stacksize()>0 && this->player2.stacksize()>0){ // if both of the players have cards in the hand the game is not finished.
        return false;
    }
    return true;
}
void Game:: playTurn(){ // function that play a turn until one player takes cards from the table.
    if(this->isFinished()){ // if the game has finished (one of the players finished his hand) the function throws exeption.
        throw invalid_argument("The Game has finished.");
        return;
    }
     if (&player1 == &player2) { // if the game started with the same player the function throws exeption.
        throw invalid_argument("Both of the players are the same player.");
    }
    string turnLog=""; // initialize a string that will describe the turn and will be pushed to the log.
    int cardsOnTable = 0, v1=0, v2=0; // initialize a counter that counts the cards on the table, and two variables for the values of the cards.
    while(!this->isFinished() && v1 == v2){ // repeat the actions until one player wins or finish his hand.
        Card c1(this->player1.throwCard()); // c1 is the card that player1 throws.
        turnLog += player1.getName() + " played " +c1.toString()+" "; // add the action to the log. 
        Card c2(this->player2.throwCard()); // c2 is the card that playr2 throws.
        turnLog+=player2.getName()+" played " +c2.toString()+". "; // add the action to the log. 
        cardsOnTable += 2; // both of the players throwed a card so we have more two cards on the table.
        v1 = c1.getNumber(); // v1 is the value of the card c1 of player1.
        v2 = c2.getNumber(); // v2 is the value of the card c2 of player2.
        if(v1 == v2){ // if v1 = v2 we have a draw.
            turnLog += "Draw. "; // report the draw to the log.
            this-> drawCounter +=1; // promote the draw counter.
            this-> turnsCounter +=1; // promote the turns counter.
            if(!this->isFinished()){ // if the game has not finished the players throws a flipped card and the loop will have more iteration to break the draw.
                Card c1(this->player1.throwCard()); // flipped card.
                Card c2(this->player2.throwCard());  // flipped card.
                cardsOnTable += 2; // more two cards are on the table.
            }
            if(this->isFinished()){ // if the game finish while a draw the players take the cards equally.
                this-> player1.take(cardsOnTable/2); // player1 take half of the cards from the table.
                this-> player2.take(cardsOnTable/2); // player2 take half of the cards from the table.
            }

        }
        else if(v1 >v2){ // if v1 grater than v2 player1 wins the turn. 
            this-> player1.take(cardsOnTable); // player1 takes all the cards from the table.
            this-> player1.winCard(c1.getSerialNum()); // add c1 (the win card) to the list of the win cards of player1. 
            turnLog += this-> player1.getName()+" wins."; // add the action to the log. 
            this-> player2.lose(); // promote the lose counter of player2.
            this-> turnsCounter +=1 ; // promote the turns counter.
        }
        else{ // if v2 grater than v1 player2 wins the turn. 
            this-> player2.take(cardsOnTable); // player2 takes all the cards from the table.
            this-> player2.winCard(c2.getSerialNum()); // add c2 (the win card) to the list of the win cards of player2.
            turnLog += this-> player2.getName()+" wins."; // add the action to the log. 
            this-> player1.lose(); // promote the lose counter of player1.
            this-> turnsCounter +=1; // promote the turns counter.
        }
    }
    this-> log.push_back(turnLog); // add the turns log to the end of the log list.

}
void Game:: printLastTurn(){ // print the last turn that is the first argument in the log list.
    cout << this->log.front() << endl;
}
void Game:: playAll(){ // play turns until the game will finish.
    while(!this->isFinished())
        this-> playTurn();
}
void Game:: printWiner(){ // print the name of the winner, using cardsTaken function of Player that checks how many cards the player took in the game.
    int t1 = this-> player1.cardesTaken(), t2 = this-> player2.cardesTaken(); // t1 is the number of the cards that player1 took, t2 is the number of the cards that player2 took.
    if(t1>t2) // player1 wins.
        cout << this->player1.getName() << endl; // prints the name of player1.
    else if(t2>t1) // player2 wins.
        cout << this->player2.getName() << endl;; // prints the name of player1.
    else // the game finished with a draw.
        cout << "Draw." << endl; // prints draw.
}
void Game:: printLog(){ // prints all the arguments in the log list, it will describe the all actions in the game.
    for (auto i : this-> log) {
        cout << i << endl;
    }
}
void Game:: printStats(){ // prints the states of the game.
    cout << ""<< endl;
    cout << "Game States:" << endl;
    cout << "Amount of draws: " + to_string(this->drawCounter)<< endl; // prints the amount of the draws of the game.
    cout << "Amount of turns: " + to_string(this->turnsCounter)<< endl; // prints the amount of the turns of the game.
    float rate = (float)this->drawCounter/ (float)this->turnsCounter;
    cout << "Draw rate: " + to_string((int)(rate*100))+"%\n"<< endl; // prints the precent of the draws from all the turns.
    cout << this-> player1.states() << endl; // prints the states of the player1.
    cout << this-> player2.states() << endl; // prints the states of the player2.
}

