#include "Player.hpp"

class Game{
private:
    Shoe* shoe;
    Player* player;
    Dealer* dealer;
public:
    Game();
    void startGame();
    void iteration();
};

Game::Game(){
    string p_name;
    int cash;
    cout << "Enter your name: ";
    cin >> p_name;
    cout << "Enter the amount of cash to start with: ";
    cin >> cash;
    player = new Player(p_name, cash);

    dealer = new Dealer();

    shoe = new Shoe();

    shoe->Shuffle();

}

void Game::iteration(){
    int bet;
    cout << "Place your bet: ";
    cin >> bet;
    cout << "Starting new round..." << endl;

    dealer->addCard(shoe ->dealCard());
    dealer->addCard(shoe ->dealCard());
    player->addCard(shoe ->dealCard());
    player->addCard(shoe ->dealCard());

    cout << "Your hand: " << endl;
    player -> getHands();

    cout << "Dealer's card: " << endl;
    dealer -> showCard();
 
    if (player -> getScores() == 21){
        player->addCash(bet*3/2);
        return;
    }
    bool stand = false;
        while(!stand){
        if (player -> getScores() > 21){
            cout << "Your score exceeded 21! You lost!" << endl;
            player->addCash(-bet);
            return;
        }
        cout << "Do you want to hit? (y/n)";
        char c; cin >> c;
        if (c == 'y'){
            Card* dealt = shoe -> dealCard();
            player -> addCard(dealt);
            cout << "You were dealt: " << endl;
            cout << dealt << endl;
        } 
        else stand = true;
    }
    while (dealer -> getScores() < 17){
        cout << "Dealer is drawing from the deck..." << endl;
        dealer -> addCard(shoe -> dealCard());
    }
    if (player -> getScores() > dealer -> getScores()){
        cout << "Your score is greater than the dealer's score! You won! " << endl;
        player -> addCash(bet);
        return;
    } else if (player -> getScores() < dealer -> getScores()){
        cout << "You lost!" << endl;
        player -> addCash(-bet);
    }
    return;
}

void Game::startGame(){
    while (player -> getCash() > 0){
        iteration();
    }
}