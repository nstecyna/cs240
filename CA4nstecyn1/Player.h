#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

class Player {
	public:
	  string name;
	  int wins;
	  LLC<PlayingCard> card;

		Player();
		Player(string n);
		friend ostream& operator << (ostream & out, const Player& p);
};
