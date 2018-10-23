#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

int main() {
	cout << "Test 1" << endl;
	PlayingCard c1(5,"C");

	cout << "Test 2" << endl;
	PlayingCard c2(13,"C");

	cout << "Test 3" << endl;
	cout << "false : " << (c1 == c2) << endl;

	cout << "Test 4" << endl;
	cout << "false : " << (c1 > c2) << endl;

	cout << "Test 5" << endl;
	cout << "true : " << (c2 > c1) << endl;

	cout << "Test 6" << endl;
	PlayingCard c3(13,"C");
	cout << "true : " << (c2 == c3) << endl;

	cout << "Test 7" << endl;
	cout << "false : " << (c2 > c3) << endl;
	cout << "false : " << (c3 > c2) << endl;
}
