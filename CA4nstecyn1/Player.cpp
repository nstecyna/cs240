#include <iostream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

Player::Player() {
	name = "";
	gWins = 0;
	bWins = 0;
	wWins = 0;
	handsPlayed = 0;
	cards = new LLC<PlayingCard>();
}

Player::Player(string n) {
	name = n;
	gWins = 0;
	bWins = 0;
	wWins = 0;
	handsPlayed = 0;
	cards = new LLC<PlayingCard>();
}

Player::~Player() {
	delete(cards);
}

ostream& operator << (ostream & out, const Player& p) {
	out << p.name;
	return out;
}

void Player::setName(string n) {
	name = n;
}
