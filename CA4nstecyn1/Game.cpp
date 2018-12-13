#include <stdlib.h>
#include "Game.h"

using namespace std;

Game::Game() {
	cards = new LLC<PlayingCard>();
}

Game::~Game() {
	delete cards;
}

Player* Game::play(Player *p1, Player *p2, ofstream *file, GameData &data) {
	*file << *p1 << " VS. " << *p2 << endl;	

	setDeck();
	dealCards(p1, p2);

	int p1Battles = p1->handsPlayed;
	int p2Battles = p2->handsPlayed;

	int counter = 0;
	while (p1->cards->len() > 0 && p2->cards->len() > 0 ) {
		counter++;
		*file << "\tBattle " << counter << ": ";
		battle(p1, p2, file);
		*file << " : " << *p1 << " " << p1->cards->len() << ", " << *p2 << " " << p2->cards->len() << endl;
		if (counter >= 1000) {
			break;
		}
	}

	Player *winner;
	winner = (p1->cards->len() > p2->cards->len())? p1 : p2;
	winner->gWins++;
	if (winner == p1){
		data.totalBattles += (p1->handsPlayed - p1Battles);
		if (data.topBattles < (p1->handsPlayed - p1Battles))
			data.topBattles = (p1->handsPlayed - p1Battles);

		*file << *p1 << " DEFEATED " << *p2 <<  " in " << winner->bWins << " Battles and " << winner->wWins <<  " Wars" << endl;
	} else {
		data.totalBattles += (p2->handsPlayed - p2Battles);
		if (data.topBattles < (p2->handsPlayed - p2Battles))
			data.topBattles = (p2->handsPlayed - p2Battles);

		*file << *p2 << " DEFEATED " << *p1 <<  " in " << winner->bWins << " Battles and " << winner->wWins <<  " Wars" << endl;
	}
	return winner;
}

void Game::battle(Player *p1, Player *p2, ofstream *file) {
	p1->handsPlayed++;
	p2->handsPlayed++;
		
	cards->insert(p1->cards->takeFirstElement());
	cards->insert(p2->cards->takeFirstElement());

	if (cards->first->data > cards->last->data) {
		*file << *p1 << " " << cards->first->data.name << " DEFEATED " << *p2 << " " << cards->last->data.name;
		p1->bWins++;
		p1->cards->insert(cards->takeFirstElement());
		p1->cards->insert(cards->takeFirstElement());
	} else if (cards->first->data == cards->last->data) {
		*file << *p1 << " " << cards->first->data.name << " TIED " << *p2 << " " << cards->last->data.name;
		war(p1, p2, file); 
	} else {
		*file << *p2 << " " << cards->first->data.name << " DEFEATED " << *p1 << " " << cards->last->data.name;
		p2->bWins++;
		p2->cards->insert(cards->takeFirstElement());
		p2->cards->insert(cards->takeFirstElement());
	}
}

void Game::war(Player *p1, Player *p2, ofstream *file) {
	p1->wWins++;
	p2->wWins++;

	PlayingCard temp;

	PlayingCard card1;
	PlayingCard card2;

	int moreCards = 0;

	if (p1->cards->len() == 0) {
		p2->bWins++;
		for (int i = 0; i< cards->len(); i++){
			p2->cards->insert(cards->takeFirstElement());
		}
	} else if (p2->cards->len() == 0) {
		for (int i = 0; i< cards->len(); i++){
			p1->cards->insert(cards->takeFirstElement());
		}
		p1->bWins++;
	}

	if (p1->cards->len() < 4) {
		for (int i = 0; i < p1->cards->len() ; i++){
			temp = p1->cards->takeFirstElement();
			cards->insert(temp);
		}
		card1 = temp;
	} else {
		for (int i = 0; i < 4 ; i++) {
			temp = p1->cards->takeFirstElement();
			cards->insert(temp);
		}
		card1 = temp;
		moreCards++;
	}

	if (p2->cards->len() < 4) {
		for (int i = 0; i < p2->cards->len() ; i++){
			temp = p2->cards->takeFirstElement();
			cards->insert(temp);
		}
		card1 = temp;
	} else {
		moreCards++;
		for (int i = 0; i < 4 ; i++) {
			temp = p2->cards->takeFirstElement();
			cards->insert(temp);
		}
		card1 = temp;
	}

	if (card1 > card2) {
		p1->bWins++;
		for (int i = 0; i< cards->len();) {
			p1->cards->insert(cards->takeFirstElement());
		}
	} else if (card2 > card1) {
		p2->bWins++;
		for (int i = 0; i< cards->len();) {
			p1->cards->insert(cards->takeFirstElement());
		}
	} else {
		if (moreCards == 2) {
			war(p1, p2, file);
		} else if (moreCards == 1) {
			Player* temp2 = (p1->cards->len() > p2->cards->len())? p1 : p2;
			temp2->gWins++;
			for (int i = 0; i< cards->len();){ 
				temp2->cards->insert(cards->takeFirstElement());
			}
		} else {
			p1->bWins++;
			for (int i = 0; i< cards->len();){
				p1->cards->insert(cards->takeFirstElement());
			}
		}
	}
}

void Game::setDeck() {
	cards->empty();

	for(int i = 2; i < 15; i++){ 
		cards->insert(PlayingCard(i, "S")); 
		cards->insert(PlayingCard(i, "H"));
		cards->insert(PlayingCard(i, "D")); 
		cards->insert(PlayingCard(i, "C")); 
	}

	/*
	   string suits[4] = {"S", "H", "C", "D"};
	   for (int i = 0; i < 4; i++) {
	   for (int j = 14; j > 1; j--) {
	   cards->insert(PlayingCard(j, suits[i]));
	   cout << cards->len() << endl;

	// don't know why this version doesn't work
	*/
	cards->shuffle();
}

void Game::dealCards(Player *p1, Player *p2) {
	for (int i = 0; i < 26; i++) {
		p1->cards->insert(cards->takeLastElement());
	}
	for (int i = 26; i < 52; i++) {
		p2->cards->insert(cards->takeFirstElement());
	}
}
