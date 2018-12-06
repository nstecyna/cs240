#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unordered_map>
#include "City.h"

using namespace std;

void AnyItinerary(unordered_map<string ,City*> cities, string departCity, string arriveCity) {
	cout << "TODO" << endl;
}


void EarliestArrival(unordered_map<string ,City*> cities, string departCity, string arriveCity, string departTime, string arriveTime) {
	AnyItinerary(cities, departCity, arriveCity);
}

void LeastExpensive(unordered_map<string ,City*> cities, string departCity, string arriveCity, string departTime, string arriveTime) {
	EarliestArrival(cities, departCity, arriveCity, departTime, arriveTime);
}

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
	cout << endl << "Please pick an objective:" << endl;
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


	// vector<Flight> flights;
	unordered_map<string ,City*> cities;

	ifstream reader;
	reader.open(argv[1]);

	string depCityN;
	string destCityN;
	string depTime;
	string arrTime;
	string cost;

	bool newDepCity = true;
	bool newDestCity = true;

	City *newCity;
	Flight *newFlight;

	while (reader >> depCityN >> destCityN >> depTime >> arrTime >> cost) {

		// reader >> depCityN;
		// reader >> destCityN;
		// reader >> depTime;
		// reader >> arrTime;
		// reader >> cost;

		newFlight = new Flight(depCityN, destCityN, depTime, arrTime, cost);


		if (cities[depCityN] == NULL) {
			newCity = new City(depCityN);
			cities[depCityN] = newCity;
		}

		if (cities[destCityN] == NULL) {
			newCity = new City(destCityN);
			cities[destCityN] = newCity;
		}

		newFlight->destCity = cities[destCityN];
		cities[depCityN]->flightsOut.push_back(newFlight);		

	}
	reader.close();

	// flights.pop_back();
	
	if (choose == "1") {
		AnyItinerary(cities, departCity, arriveCity);
	} else if (choose == "2") {
		EarliestArrival(cities, departCity, arriveCity, departTime, arriveTime);
	} else {	
		LeastExpensive(cities, departCity, arriveCity, departTime, arriveTime);
	}

	delete newCity;
	delete newFlight;



}
