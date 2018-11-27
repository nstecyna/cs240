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

	vector<Flight>* flights;

	ifstream reader;
	reader.open(argv[1]);

	string depCity;
	string desCity;
	string depTime;
	string arrTime;
	string cost;

	vector<Flight>::iterator i = flights->begin();
	while (reader.good()) {
		reader >> depCity;
		reader >> desCity;
		reader >> depTime;
		reader >> arrTime;
		reader >> cost;
		
		flights->push_back(Flight(depCity, desCity, depTime, arrTime, cost));

		cout << i->depCity << endl;
		cout << i->desCity << endl;
		cout << i->depTime << endl;
		cout << i->arrTime << endl;
		cout << i->cost << endl;
		cout << endl;

		++i;
	}
	reader.close();

	
}

void setReturnFlights(string tripDepCity, int earliestDep, int earliestRet, vector<Flight>& flights) {
	
	for (auto i = flights.begin(); i != flights.end(); ++i) {
		if (i->depCity == tripDepCity && earliestDep < i->depTime) {
			for (auto j = flights.begin() + 1; j != flights.end(); ++j) {
				if (i->desCity == j->depCity && i->arrTime < j->depTime && earliestRet < j->depTime)
					i->returnFlights->push_back(*j);
			}
		}
		for (auto k = i->returnFlights->begin() + 1; k != i->returnFlights->end(); ++k) {
			cout << k->depTime << endl;
		}
	}
}
