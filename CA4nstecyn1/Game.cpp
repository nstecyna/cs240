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
	cards->shuffle();
	dealCards(p1, p2);
	
	int p1Battles = p1->handsPlayed;
	int p2Battles = p2->handsPlayed;

	int counter = 0;
	while (p1->cards->len() > 0 && p2->cards->len() > 0 ) {
		counter++;
		*file << "Battle " << counter << ": ";
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
		if (data.topBattles < (p1->handsPlayed - p1Battles)) data.topBattles = (p1->handsPlayed - p1Battles);

		*file << *p1 << " DEFEATED " << *p2 <<  " in " << winner->bWins << " Battles and " << winner->wWins <<  " Wars" << std::endl;
	} else {
		data.totalBattles += (p2->handsPlayed - p2Battles);
		if (data.topBattles < (p2->handsPlayed - p2Battles)) data.topBattles = (p2->handsPlayed - p2Battles);

		*file << *p2 << " DEFEATED " << *p1 <<  " in " << winner->bWins << " Battles and " << winner->wWins <<  " Wars" << std::endl;
	}
	return winner;
}

void Game::battle(Player *p1, Player *p2, ofstream *file) {
	cards->insert(p1->cards->takeFirstElement());
	cards->insert(p2->cards->takeFirstElement());
	
	if (cards->first > cards->last) {
		*file << *p1 << " " << cards->first << " DEFEATED " << *p2 << " " << cards->last;
		p1->bWins++;
		p1->cards->insert(cards->takeFirstElement());
		p1->cards->insert(cards->takeFirstElement());
	} else if (cards->first == cards->last) {
		*file << *p1 << " " << cards->first << " TIED " << *p2 << " " << cards->last;
                war(p1, p2, file); 
	} else {
		*file << *p2 << " " << cards->first << " DEFEATED " << *p1 << " " << cards->last;
		p2->bWins++;
		p2->cards->insert(cards->takeFirstElement());
		p2->cards->insert(cards->takeFirstElement());
	}
}

void Game::war(Player *p1, Player *p2, ofstream *file) {

}

void Game::setDeck() {
	cards->empty();
	string suits[4] = {"S", "H", "C", "D"};
	for (int i = 0; i < 4; i++) {
		for (int j = 14; j > 1; j--) {
			cards->insert(PlayingCard(j, suits[i]));
		}
	}
}

void Game::dealCards(Player *p1, Player *p2) {
	for (int i = 0; i < 26; i++) {
    		p1->cards->insert(cards->takeFirstElement());
  }
  	for (int i = 26; i < 52; i++) {
  		p2->cards->insert(cards->takeFirstElement());
  }
}
