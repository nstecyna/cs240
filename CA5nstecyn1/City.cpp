#include <stdlib.h>
#include <string>
#include <vector>
#include "City.h"


using namespace std;

City::City() {
	name = "";
	discovered = 0;
	arrival= 0;
	weight = 0;
	prevCity = nullptr;
	prevFlight = nullptr;
}

City::~City() {
	/*
	   for (Flight* i : flightsOut) {
	   delete i;
	   }
	   flightsOut.clear();
	   */
}

City::City(std::string n) {
	name = n;
	discovered = 0;
	arrival = 0;
	weight = 0;
	prevCity = nullptr;
	prevFlight = nullptr;

}

City::City(std::string n, Flight *flight) {
	name = n;
	discovered = false;
	weight = 0;
	arrival = false;
	flightsOut.push_back(flight);
	prevCity = nullptr;
	prevFlight = nullptr;

}
