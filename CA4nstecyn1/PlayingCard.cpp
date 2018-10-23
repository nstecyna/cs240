#include <iostream>
#include <stdlib.h>
#include "PlayingCard.h"

using namespace std;

PlayingCard::PlayingCard() {
	value = 0;
	suit = "";
}

PlayingCard::PlayingCard(int v, string s) {
	value = v;
	suit = s;
}

ostream& operator << (ostream & out, const PlayingCard& pc) {
	string v = "";
	
	if (pc.value > 13) v = "A";
	else if (pc.value > 12) v = "K";
	else if (pc.value > 11) v = "Q";
	else if (pc.value > 10) v = "J";
	else v = to_string(pc.value);

	out << v << pc.suit;

    	return out;
}

bool PlayingCard::operator==(const PlayingCard& pc) {
	if (value == pc.value) return true;
	return false;
}

bool PlayingCard::operator>(const PlayingCard& pc) {
	if (value > pc.value) return true;
	return false;
}
