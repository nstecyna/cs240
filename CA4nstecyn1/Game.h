#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Player.h"

using namespace std;

class GameData{
	public:
		int totalBattles;
		int topBattles;
		GameData() {
			totalBattles = 0;
			topBattles = 0;
		}
};

class Game {
	public:
      		LLC<PlayingCard>* cards;

		Game();
		Game(string n1, string n2);
		~Game();
		Player* play(Player *p1, Player *p2, ofstream *file, GameData &data);
		void battle(Player *p1, Player *p2, ofstream *file);
		void war(Player *p1, Player *p2, ofstream *file);

	private:
		void setDeck();
		void dealCards(Player *p1, Player *p2);
};
