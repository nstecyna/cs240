#include <iostream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

Player::Player() {
	name = "";
	wins = 0;
	cards = new LLC<PlayingCard>();
}

Player::Player(string n) {
	name = n;
	wins = 0;
	cards = new LLC<PlayingCard>();
}

ostream& operator << (ostream & out, const Player& p) {
	out << p.name;
  return out;
}

void Player::setName(string n) {
	name = n;
}
