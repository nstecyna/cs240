#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Game.h"

using namespace std;

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

	for (int i = 0; i < players.size(); ++i) {
		delete players[i];
	}

	writer.close();
	reader.close();
}
