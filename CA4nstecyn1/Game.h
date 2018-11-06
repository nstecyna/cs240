#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Player.h"

using namespace std;

class gameData{
	public:
		int totalbattles = 0;
		int topBattles = 0;
};

class Game {
	public:
	  Player p1;
	  Player p2;
	  LLC<PlayingCard>* cards;

	  Game();
	  Game(string n1, string n2);
	  ~Game();

		Player play(ofstream *file);
		void battle(ofstream *file);
		void war(ofstream *file);

	private:
		void setDeck();
		void dealCards();
};
