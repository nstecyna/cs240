#include <stdlib.h>
#include <string>
#include <vector>
#include "City.h"


using namespace std;

City::City() {
	name = "";
	discovered = false;
	weight = 0;
	explored = false;
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
	int traversed;
	int weight;
}

City::City(std::string n, Flight *flight) {
	name = n;
	int traversed;
	int weight;
	flightsOut.push_back(flight);
}
