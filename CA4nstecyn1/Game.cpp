#include <stdlib.h>
#include "Game.h"

using namespace std;

Game::Game() {
	p1.setName("Player 1");
	p2.setName("Player 2");
	cards = new LLC<PlayingCard>();
	setDeck();
}

Game::Game(string n1, string n2) {
	p1.setName(n1);
	p2.setName(n2);
	cards = new LLC<PlayingCard>();
	setDeck();
}

Game::~Game() {
	delete cards;
}

Player Game::play(ofstream *file) {
	*file << p1 << " VS. " << p2 << endl;
	cards->shuffle();
	dealCards();
}

void Game::battle(ofstream *file) {
	cards->insert(p1.cards->takeFirstElement());
	cards->insert(p2.cards->takeFirstElement());
	
	if (cards->first > cards->last) {
		*file << p1 << " " << cards->first << " DEFEATED " << p2 << " " << cards->last;
		p1.bWins++;
		p1.cards->insert(cards->takeFirstElement());
		p1.cards->insert(cards->takeFirstElement());
	} else if (cards->first == cards->last) {
		*file << p1 << " " << cards->first << " TIED " << p2 << " " << cards->last;
                war(file); 
	} else {
		*file << p2 << " " << cards->first << " DEFEATED " << p1 << " " << cards->last;
		p2.bWins++;
		p2.cards->insert(cards->takeFirstElement());
		p2.cards->insert(cards->takeFirstElement());
	}
}

void Game::war(ofstream *file) {

}

void Game::setDeck() {
	string suits[4] = {"S", "H", "C", "D"};
	for (int i = 0; i < 4; i++) {
		for (int j = 14; j > 1; j--) {
			cards->insert(PlayingCard(j, suits[i]));
		}
	}
}

void Game::dealCards() {
	for (int i = 0; i < 26; i++) {
    		p1.cards->insert(cards->takeFirstElement());
  }
  	for (int i = 26; i < 52; i++) {
  		p2.cards->insert(cards->takeFirstElement());
  }
}
