#include <stdlib.h>
#include "Flight.h"


using namespace std;

Flight::Flight() {
	depCity = "";
	desCity = "";
	depTime = 0;
	arrTime = 0;
	cost = 0.0;
	returnFlights = new vector<Flight>;
}

Flight::~Flight() {
	delete returnFlights;
}

Flight::Flight(string depC, string desC, string depT, string arrT, string c) {
	depCity = depC;
	desCity = desC;
	cost = ::atof(c.substr(1).c_str());
	returnFlights = new vector<Flight>;

	// departure time
	int colon = 2;
	if (depT[1] == ':')
		colon = 1;

	depTime = 60 * atoi(depT.substr(0,colon).c_str());
	depTime += atoi(depT.substr(colon+1, 2).c_str());
	
	if (depT[colon + 3] == 'p')
		depTime = 0;

	// arrival time
	if (arrT[1] == ':')
		colon = 1;
	else
		colon = 2;

	arrTime = 60 * atoi(arrT.substr(0,colon).c_str());
	arrTime += atoi(arrT.substr(colon+1, 2).c_str());
	
	if (arrT[colon + 3] == 'p')
		arrTime += 720;
}
