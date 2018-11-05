#include <iostream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

class Game {
	public:
	  Player p1;
	  Player p2;
	  LLC<PlayingCard>* cards = new LLC<PlayingCard>;

	  Game();
	  Game(string n1, string n2);
	  ~Game();

	private:
		void setDeck();
};
