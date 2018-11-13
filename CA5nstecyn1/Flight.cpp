#include <stdlib.h>
#include "Flight.h"


using namespace std;

Flight::Flight() {
	depCity = "";
	desCity = "";
	depTime = 0;
	arrTime = 0;
	cost = 0.0;
}

Flight::Flight(string depC, string desC, string depT, string arrT, string c) {
	depCity = depC;
	desCity = desC;

	depTime = 0;
	arrTime = 0;

	
	cost = ::atof(c.substr(1).c_str());
}

string Flight::strDepTime(){

}

string Flight::strArrTime() {

}
