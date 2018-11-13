#include <stdlib.h>
#include <string>

using namespace std;

class Flight{
	public:
		string depCity;
		string desCity;
		int depTime;
		int arrTime;
		float cost;

		Flight();
		Flight(string depC, string desC, string depT, string arrT, string c);
		string strDepTime();
		string strArrTime();
}
