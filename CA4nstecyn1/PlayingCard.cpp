#include <iostream>
#include <stdlib.h>
#include "PlayingCard.h"

using namespace std;

PlayingCard::PlayingCard() {
	value = 14;
	name = "AS";
}

PlayingCard::PlayingCard(int v, string s) {
	value = v;

	if (v > 13) name = "A";
	else if (v > 12) name = "K";
	else if (v > 11) name = "Q";
	else if (v > 10) name = "J";
	else name = to_string(v);

	name += s;
}

PlayingCard::~PlayingCard() {

}


ostream& operator << (ostream & out, const PlayingCard& pc) {
	}

bool PlayingCard::operator==(const PlayingCard& pc) {
	if (value == pc.value) return true;
	return false;
}

bool PlayingCard::operator>(const PlayingCard& pc) {
	if (value > pc.value) return true;
	return false;
}
