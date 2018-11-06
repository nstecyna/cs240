#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Game.h"

using namespace std;

Game *game = new Game();

vector<Player*> tournament(vector<Player*> &players, ofstream &out, GameData &data);

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Please enter a valid number of arguments." << endl;
		return 1;
	}
	
	GameData data;
	vector<Player*> players;
	ifstream reader;
	ofstream writer;
	writer.open(argv[2]);
	reader.open(argv[1]);
	reader >> noskipws;

	string line;
	Player * temp;
	int size;
	while (getline(reader, line)) {
		if (line.length() > 1) {
			temp = new Player(line);
			players.push_back(temp);
		}
	}
	unsigned int iter= 1;
	size = players.size();
	while (iter < size) iter *= 2;

	if (iter != size) {
		cout << "Number of players is not a power of two." << endl;
		return 1;
	}

	vector<Player*> winnerVector = tournament(players, writer, data);
	Player *winner = (winnerVector)[0]; 
	writer << "Winner: " << *winner << ". Average number of battles in the tournament: " << (data.totalBattles/(size-1)) << " The greatest number of battles in a single tournament was " << data.topBattles << endl;

	delete winner;
	delete game;

	writer.close();
	reader.close();
}

vector<Player*> tournament(vector<Player*> &players, ofstream &out, GameData &data){
	vector<Player*> roundWinners;
	for (unsigned int i = 0; i < players.size() - 1; i += 2) {
		out << "===" << endl;

		Player* winner = game->play(players[i], players[i+1], &out, data);

		if (winner == players[i])
			delete players[i+1];
		else
			delete players[i];

		winner->cards->empty();
		winner->gWins = 0;
		winner->bWins = 0;
		winner->wWins = 0;
		roundWinners.push_back(winner);
	}

	if (roundWinners.size() == 1)
		return roundWinners;

	return tournament(roundWinners, out, data);
}

