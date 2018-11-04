#include <iostream>
#include <stclib.h>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

Player::Player() {
	name = "";
	wins = 0;
}

Player::Player(string n) {
	name = n;
	wins = 0;
}

ostream& operator << (ostream & out, const Player& p) {
	out << name;
  return out;
}
