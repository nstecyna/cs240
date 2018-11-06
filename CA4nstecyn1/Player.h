#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

class Player {
	public:
	  string name;
	  int bWins;
	  int wWins;
	  LLC<PlayingCard>* cards;

		Player();
		Player(string n);
		~Player();
		friend ostream& operator << (ostream & out, const Player& p);
		void setName(string n);
};
