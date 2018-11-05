#include <iostream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

class Game {
	public:
	  Player p1;
	  Player p2;
	  LLC<PlayingCard>* cards;

	  Game();
	  Game(string n1, string n2);
	  ~Game();

		void play();
    void battle();
    void war();

	private:
		void setDeck();
		void dealCards();
};
