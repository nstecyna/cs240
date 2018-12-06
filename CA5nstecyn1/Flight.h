#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class City;

class Flight{
	public:
		string depCityN;
		string destCityN;
		int depTime;
		int arrTime;
		float cost;
		City *destCity;

		Flight();
		~Flight();
		Flight(string depCN, string destCN, string depT, string arrT, string c);
		Flight(const Flight &f);
		int convertTimeToInt(string time);
		string convertIntToTime(int i);
		string getDepTime();
		string getArrTime();
};
