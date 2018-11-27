#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Flight{
	public:
		string depCity;
		string desCity;
		int depTime;
		int arrTime;
		float cost;
		vector<Flight>* returnFlights;

		Flight();
		~Flight();
		Flight(string depC, string desC, string depT, string arrT, string c);
};
