#include <iostream>
#include <stdlib.h>
#include "Game.h"

using namespace std;

Game::Game() {
	p1.setName("Player 1");
	p2.setName("Player 2");
	setDeck();
}

Game::Game(string n1, string n2) {
	p1.setName(n1);
	p2.setName(n2);
	setDeck();
}

void Game::setDeck() {
	string suits[4] = {"S", "H", "C", "D"};
	for (int i = 0; i < 4; i++) {
		for (int j = 14; j > 1; j--) {
			cards.insert(PlayingCard(j, suits[i]));
		}
	}
}
