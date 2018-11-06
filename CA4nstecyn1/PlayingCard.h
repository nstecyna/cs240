#include <iostream>
#include <stdlib.h>

using namespace std;

class PlayingCard {
	public:
		int value;
		string suit;

		PlayingCard();
		~PlayingCard();
		PlayingCard(int v, string s);
		friend ofstream& operator << (ofstream & out, const PlayingCard& pc);
		bool operator==(const PlayingCard& pc);
		bool operator>(const PlayingCard& pc);
};
