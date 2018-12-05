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
	returnFlights->clear();
	delete returnFlights;
}

Flight::Flight(string depC, string desC) {
	depCity = depC;
	desCity = desC;
	depTime = 0;
	arrTime = 0;
	cost = 0.0;
	returnFlights = new vector<Flight>;
}

Flight::Flight(string depC, string desC, string depT, string arrT) {
	depCity = depC;
	desCity = desC;
	cost = 0.0;
	returnFlights = new vector<Flight>;

	// departure time
	bool zeroInHour = false;
	if (depT[0] == '0')
		zeroInHour = true;

	if (zeroInHour)
		depTime = 60 * atoi(depT.substr(1, 1).c_str());
	else
		depTime = 60 * atoi(depT.substr(0, 2).c_str());
	depTime += atoi(depT.substr(4, 2).c_str());
	
	if (depT[6] == 'p')
		depTime += 720;

	// arrival time
	if (arrT[0] != '0')
		zeroInHour = false;

	if (zeroInHour)
		arrTime = 60 * atoi(arrT.substr(1, 1).c_str());
	else
		arrTime = 60 * atoi(arrT.substr(0, 2).c_str());
	arrTime += atoi(arrT.substr(4, 2).c_str());
	
	if (arrT[6] == 'p')
		arrTime += 720;

}

Flight::Flight(string depC, string desC, string depT, string arrT, string c) {
	depCity = depC;
	desCity = desC;
	cost = ::atof(c.substr(1).c_str());
	returnFlights = new vector<Flight>;

	// departure time
	bool zeroInHour = false;
	if (depT[0] == '0')
		zeroInHour = true;

	if (zeroInHour)
		depTime = 60 * atoi(depT.substr(1, 1).c_str());
	else
		depTime = 60 * atoi(depT.substr(0, 2).c_str());
	depTime += atoi(depT.substr(4, 2).c_str());
	
	if (depT[5] == 'p')
		depTime += 720;

	// arrival time
	if (arrT[0] != '0')
		zeroInHour = false;

	if (zeroInHour)
		arrTime = 60 * atoi(arrT.substr(1, 1).c_str());
	else
		arrTime = 60 * atoi(arrT.substr(0, 2).c_str());
	arrTime += atoi(arrT.substr(4, 2).c_str());
	
	if (arrT[5] == 'p')
		arrTime += 720;

}

Flight::Flight(const Flight &f) {
	depCity = f.depCity;
	desCity = f.desCity;
	depTime = f.depTime;
	arrTime = f.arrTime;
	cost = f.cost;
	returnFlights = new vector<Flight>;

	for (auto i = f.returnFlights->begin(); i != f.returnFlights->end(); ++i) {
		returnFlights->push_back(*i);
	}
}
