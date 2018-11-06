#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

class Player {
	public:
		string name;
		int gWins;
		int bWins;
		int wWins;
		int handsPlayed;
		LLC<PlayingCard>* cards;

		Player();
		Player(string n);
		~Player();
		friend ostream& operator << (ostream & out, const Player& p);
		void setName(string n);
};
