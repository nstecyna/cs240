#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void newVoter(string &lastName, string &firstName, int &age, int &streetNum, string &streetName, string &town, string &zipCode, float &amtDonated);
void update(string &lastName, string &firstName, int &age, int &streetNum, string &streetName, string &town, string &zipCode);
void view(string &lastName, string &firstName, int &age, int &streetNum, string &streetName, string &town, string &zipCode, float &amtDonated);
void donate(float &amtDonated);
void report(string &lastName, float &amtDonated);
