#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Flight.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Please enter a valid number of arguments." << endl;
		return 1;
	}

	

	ifstream reader;
	reader.open(argv[1]);

	string depCity;
	string desCity;
	string depTime;
	string arrTime;
	string cost;
	while (reader.good()) {
		reader >> depCity;
		reader >> desCity;
		reader >> depTime;
		reader >> arrTime;
		reader >> cost;

		cout << depCity << endl;
		cout << desCity << endl;
		cout << depTime << endl;
		cout << arrTime << endl;
		cout << cost << endl;
		cout << endl;
	}
	reader.close();
}


