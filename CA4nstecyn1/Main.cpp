#include <iostream>
#include <stdlib.h>
#include "Game.h"

using namespace std;

int main() {
	Player p1("cool guy");
	cout << p1;

	Game g1("hey", "fellas");
	cout << endl << g1.cards << endl;
	cout << g1.p1 << endl;
	cout << *g1.p1.cards << endl;
	cout << g1.p2 << endl;
	cout << *g1.p2.cards << endl;
}
