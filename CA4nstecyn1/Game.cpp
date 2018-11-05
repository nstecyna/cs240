#include <iostream>
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

void Game::play(){
	cards->shuffle();
	dealCards();
}

void Game::battle(){

}

void Game::war(){

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
