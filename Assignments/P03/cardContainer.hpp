#include "cards.hpp"
#include <vector>
#include <algorithm> // std::random_shuffle

/*
   ____    _    ____  ____   ____ ___  _   _ _____  _    ___ _   _ _____ ____
  / ___|  / \  |  _ \|  _ \ / ___/ _ \| \ | |_   _|/ \  |_ _| \ | | ____|  _ \
 | |     / _ \ | |_) | | | | |  | | | |  \| | | | / _ \  | ||  \| |  _| | |_) |
 | |___ / ___ \|  _ <| |_| | |__| |_| | |\  | | |/ ___ \ | || |\  | |___|  _ <
  \____/_/   \_\_| \_\____/ \____\___/|_| \_| |_/_/   \_\___|_| \_|_____|_| \_\
*/

using namespace std;

class CardContainer {
protected:
	vector<Card *> Cards;
    int capacity;

public:
	CardContainer();
	CardContainer(int);
	void Add(Card *);
	bool isEmpty();
	Card *Remove();
	void Reset();
	void Shuffle();
	int Size();
	friend ostream &operator<<(ostream &os, const CardContainer &cards);
};

CardContainer::CardContainer(){

}

CardContainer::CardContainer(int numCards){
    for (int i = 0; i < numCards; i++){
        Add(new Card(i));
    }
    capacity = numCards;
}

void CardContainer::Add(Card *card){
    if (Cards.size() < capacity) Cards.push_back(card);
}

bool CardContainer::isEmpty(){
    return Cards.size() == 0;
}

Card* CardContainer::Remove(){
    Card* card = Cards[0];
    Cards.erase(Cards.begin());

    return card;
}

void CardContainer::Reset(){
    Cards.erase(Cards.begin(), Cards.end());
    for (int i = 0; i < capacity; i++){
        Add(new Card(i));
    }
}

void CardContainer::Shuffle(){
    random_shuffle(Cards.begin(), Cards.end());
}

int CardContainer::Size(){
    return Cards.size();
}

ostream &operator<<(ostream &os, const CardContainer &c) {
	for (int i = 0; i < c.Cards.size(); i++) {
		os << "\033[0;3" << c.Cards[i]->getfColor() << ";4"
		   << c.Cards[i]->getbColor() << "m";
		os << "┌────┐";
		os << "\033[0;39;49m";
	}
	os << endl;
	for (int i = 0; i < c.Cards.size(); i++) {
		os << "\033[0;3" << c.Cards[i]->getfColor() << ";4"
		   << c.Cards[i]->getbColor() << "m";
		os << "│";
		if (c.Cards[i]->getRank() != 9) {
			os << " ";
		}
		os << c.Cards[i]->getRankChar() << " " << c.Cards[i]->getSuitChar()
		   << "│";
		os << "\033[0;39;49m";
	}
	os << endl;
	for (int i = 0; i < c.Cards.size(); i++) {
		os << "\033[0;3" << c.Cards[i]->getfColor() << ";4"
		   << c.Cards[i]->getbColor() << "m";
		os << "└────┘";
		os << "\033[0;39;49m";
	}
	os << endl;

	return os;
}


class Shoe;

/*
  ____  _____ ____ _  __
 |  _ \| ____/ ___| |/ /
 | | | |  _|| |   | ' /
 | |_| | |__| |___| . \
 |____/|_____\____|_|\_\
*/

class Deck : public CardContainer {
protected:
    friend class Shoe;
	int deckSize;

public:
	Deck();
	Deck(int);
	Card *Draw();
};

Deck::Deck():CardContainer(52){
    deckSize = 52;
}

Deck::Deck(int sz):CardContainer(sz){
    deckSize = sz;
}

Card* Deck::Draw(){
    return Remove();
}


/*
  _   _    _    _   _ ____
 | | | |  / \  | \ | |  _ \
 | |_| | / _ \ |  \| | | | |
 |  _  |/ ___ \| |\  | |_| |
 |_| |_/_/   \_\_| \_|____/
*/
class Hand : public CardContainer {
protected:
public:
	Hand();
	void Print();
	int Size() {
		return Cards.size();
	}
	void Sort();
    int getScores();
};

Hand::Hand(){
    capacity = 5;
}

void Hand::Print(){
    cout << "Your hand: " << endl;
    cout << *this << endl;
}

bool cardCmp(Card* c1, Card* c2){
    return c1 < c2;
}

void Hand::Sort(){
    sort(Cards.begin(), Cards.end(), cardCmp);
}

int Hand::getScores(){
    int sc = 0;
    for (Card* c : Cards){
        int rank = c -> getRank();
        if (rank <= 10) sc += rank;
        else sc += 10;
    }
    return sc;
}

class Shoe : public CardContainer {
protected:
    vector<Deck*> decks;
    int deck_count;
public:
    Shoe();
    Shoe(int);
    Card* dealCard();
};

Shoe::Shoe(){
    deck_count = 4;
    for (int i = 0; i < deck_count; i++){
        decks.push_back(new Deck());
    }
    for (Deck* d : decks){
        for (Card* c : d -> Cards){
            Add(c);
        }
    }
}

Shoe::Shoe(int deckCnt){
    deck_count = deckCnt;
    for (int i = 0; i < deck_count; i++){
        decks.push_back(new Deck());
    }
    for (Deck* d : decks){
        for (Card* c : d -> Cards){
            Add(c);
        }
    }
}

Card* Shoe::dealCard(){
    return Remove();
}