#include <iostream>
#include <stdlib.h>

using namespace std;

class PlayingCard {
	public:
		int value;
		string name;

		PlayingCard();
		~PlayingCard();
		PlayingCard(int v, string s);
		bool operator==(const PlayingCard& pc);
		bool operator>(const PlayingCard& pc);
};
