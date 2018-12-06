#include <stdlib.h>
//#include "Flight.h"
#include "City.h"

using namespace std;

class City;

Flight::Flight() {
	depCityN = "";
	destCityN = "";
	depTime = 0;
	arrTime = 0;
	cost = 0.0;
	destCity = nullptr;
}

Flight::~Flight() {
	/*
	   if (destCity != nullptr)
	   delete destCity;
	   */
}

Flight::Flight(string depCN, string destCN, string depT, string arrT, string c) {
	depCityN = depCN;
	destCityN = destCN;
	cost = ::atof(c.substr(1).c_str());
	destCity = nullptr;

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
	depCityN = f.depCityN;
	destCityN = f.destCityN;
	depTime = f.depTime;
	arrTime = f.arrTime;
	cost = f.cost;
	destCity = f.destCity;
}
