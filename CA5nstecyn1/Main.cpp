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

	string departCity;
	string arriveCity;
	string departTime;
	string arriveTime;

	cout << "Enter the departure city: ";
	cin >> departCity;

	cout << "Enter the destination city: ";
	cin >> arriveCity;

	cout << "Enter the earliest acceptable departure time: ";
	cin >> departTime;

	cout << "Enter the earliest acceptable return departure time: ";
	cin >> arriveTime;

	string choose;
	cout << endl << "Please pick an option:" << endl;
	cout << "Any Itinerary = type '1'" << endl;
	cout << "Earliest Arrival = type '2'" << endl;
	cout << "Least Expensive = type '3'" << endl;
	cin >> choose;

	int choice = 1;
	if (choose == "3") {
		choice = 3;
		cout << endl << "'Least Expensive' was chosen" << endl << endl;
	} else if (choose == "2") {
		choice = 2;
		cout << endl << "'Earliest Arrival' was chosen" << endl << endl;
	} else {	
		cout << endl << "'Any Itinerary' was chosen" << endl << endl;
	}


	vector<Flight> flights;

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

		flights.push_back(Flight(depCity, desCity, depTime, arrTime, cost));
	}
	reader.close();

	flights.pop_back();
	

	/**
	for (auto i = flights.begin(); i != flights.end(); ++i) {
		cout << i->depCity << endl;
		cout << i->desCity << endl;
		if (choice == 2 or choice == 3) {
			cout << i->depTime << endl;
			cout << i->arrTime << endl;
		}
		if (choice == 3)
			cout << i->cost << endl;
		cout << endl;
	}
	**/



}

/*
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
   */
