#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include "City.h"

using namespace std;

void AnyItinerary(unordered_map<string ,City*> cities, string departCity, string arriveCity, int departTime) {
	queue<City*> path;
	path.push(cities[departCity]);

	City *current;
	while (!path.empty()) {
		current = path.front();
		path.pop();
		for (auto i = current->flightsOut.begin(); i != current->flightsOut.end(); ++i) {

			if (!(*i)->destCity->discovered && (*i)->depTime >= departTime) {
				(*i)->destCity->discovered = true;

				(*i)->destCity->prevCity = current;
				(*i)->destCity->prevFlight = *i;

				(*i)->destCity->weight = (*i)->destCity->prevCity->weight + (*i)->cost;

				if ((*i)->destCity->name == arriveCity) {
					while(!path.empty())
						path.pop();
					break;
				}

				path.push((*i)->destCity);
			}
		}
	}

	stack<City*> backPath;
	City* backwardsCity = cities[arriveCity];

	while (backwardsCity != NULL){
		backPath.push(backwardsCity);
		backwardsCity = backwardsCity->prevCity;
	}
	
	if (backPath.size() < 2) {
		cout << "The destination city could not be reached. " << endl;
	} else {
		cout << "Itinerary for flight from "<< departCity << " to " << arriveCity << ":" << endl;
		while (!backPath.empty()) {
			City *temp = backPath.top();
			if (temp->prevCity != NULL) {
			cout << temp->prevFlight->depCityN << " " << temp->prevFlight->destCityN << " " << temp->prevFlight->getDepTime() << " " << temp->prevFlight->getArrTime() << " $" << temp->prevFlight->cost << endl;
			}
			backPath.pop();
		}
	}
}


void EarliestArrival(unordered_map<string ,City*> cities, string departCity, string arriveCity, int departTime, int arriveTime) {
	// TODO
}

void LeastExpensive(unordered_map<string ,City*> cities, string departCity, string arriveCity, int departTime, int arriveTime) {
	// TODO
}

Flight* compare(Flight* f1, Flight* f2) {
	if (f1->arrTime < f2->arrTime)
		return f1;
	return f2;
};

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Please enter a valid number of arguments." << endl;
		return 1;
	}

	City *newCity;
	Flight *newFlight = new Flight();

	string departCity;
	string arriveCity;
	string departTimeIn;
	string arriveTimeIn;

	cout << "Enter the departure city: ";
	cin >> departCity;

	cout << "Enter the destination city: ";
	cin >> arriveCity;

	cout << "Enter the earliest acceptable departure time: ";
	cin >> departTimeIn;
	int departTime = newFlight->convertTimeToInt(departTimeIn);

	cout << "Enter the earliest acceptable return departure time: ";
	cin >> arriveTimeIn;
	int arriveTime = newFlight->convertTimeToInt(arriveTimeIn);

	string choose;
	cout << endl << "Please pick an objective:" << endl;
	cout << "Any Itinerary = type '1'" << endl;
	cout << "Earliest Arrival = type '2'" << endl;
	cin >> choose;

	int choice = 1;
	if (choose == "2") {
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

	delete newFlight;

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
	
	for (auto i = cities.begin(); i != cities.end(); ++i) {
		sort(i->second->flightsOut.begin(), i->second->flightsOut.end(), compare);
	}

	if (cities[departCity] == NULL) {
		cout << "Invalid department city" << endl;
	} else if (cities[arriveCity] == NULL) {
		cout << "Invalid return department city" << endl;
	} else {
		if (choose == "1") {
			AnyItinerary(cities, departCity, arriveCity, departTime);
		} else if (choose == "2") {
			EarliestArrival(cities, departCity, arriveCity, departTime, arriveTime);
		} else {	
			LeastExpensive(cities, departCity, arriveCity, departTime, arriveTime);
		}
	}

	delete newCity;
	delete newFlight;



}
