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
	cost = atoi(c.substr(1).c_str());
	destCity = nullptr;
	depTime = convertTimeToInt(depT);
	arrTime = convertTimeToInt(arrT);
}

Flight::Flight(const Flight &f) {
	depCityN = f.depCityN;
	destCityN = f.destCityN;
	depTime = f.depTime;
	arrTime = f.arrTime;
	cost = f.cost;
	destCity = f.destCity;
}

int Flight::convertTimeToInt(string time) {
	int retInt = 0;
	bool zeroInHour = false;
	if (time[0] == '0')
		zeroInHour = true;

	if (zeroInHour)
		retInt = 60 * atoi(time.substr(1, 1).c_str());
	else
		retInt = 60 * atoi(time.substr(0, 2).c_str());
	retInt += atoi(time.substr(4, 2).c_str());

	if (time[5] == 'p')
		retInt += 720;
	return retInt;
}

string Flight::convertIntToTime(int i) {
	string timeOfDay = "am";
	if (i - 720 > 0) {
		timeOfDay = "pm";
		i -= 720;
	}
	string hours = to_string(i / 60);
	if (hours.length() == 1)
		hours = "0" + hours;
	string minutes = to_string(i % 60);
	if (minutes.length() == 1)
		minutes = "0" + minutes;

	return hours + ":" + minutes + timeOfDay;
}

string Flight::getDepTime() {
	return convertIntToTime(depTime);
}

string Flight::getArrTime() {
	return convertIntToTime(arrTime);
}

