#include <stdlib.h>
#include <string>
#include <vector>
#include "Flight.h"

using namespace std;

//class Flight;

class City {
	public:
		std::string name;
		vector<Flight*> flightsOut;
		bool discovered;
		int weight;
		bool explored;

		City();
		~City();
		City(std::string n);
		City(std::string n, Flight *flight);
};
