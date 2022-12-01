#include "cardContainer.hpp"

class BasePlayer{
protected:
    Hand* hand;
    string name;
public:
    BasePlayer(string);
    void addCard(Card*);
    int getScores();
};

BasePlayer::BasePlayer(string n){
    hand = new Hand();
    name = n;
}

void BasePlayer::addCard(Card* c){
    hand -> Add(c);
}

int BasePlayer::getScores(){
    return hand -> getScores();
}

class Player: public BasePlayer{
protected:
    int totalCash;
    int bet;
public:
    Player(string, int);
    void getHands();
    void removeHands();
    int getCash();
    void addCash(int);
};

Player::Player(string n, int cash):BasePlayer(n){
    totalCash = cash;
}

void Player::getHands(){
    hand -> Print();
}

void Player::removeHands(){
    delete hand;
    hand = new Hand();
}

int Player::getCash(){
    return totalCash;
}

void Player::addCash(int amount){
    totalCash += amount;
}

class Dealer : public BasePlayer{
public:
    Dealer();
    void showCard();
};

Dealer::Dealer():BasePlayer("Dealer"){

}

void Dealer::showCard(){
    hand -> show(0);
}