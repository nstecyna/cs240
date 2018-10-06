#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "VoterDB.h"

using namespace std;

void newVoter(string &lastName, string &firstName, int &age, int &streetNum, string &streetName, string &town, string &zipCode, float &amtDonated) {
   cout << "What is your last name? ";
   cin >> lastName;

   cout << "What is your first name? ";
   cin >> firstName;

   cout << "What is your age? ";
   cin >> age;

   cout << "What is your street number? ";
   cin >> streetNum;

   cout << "What is your street name? ";
   cin >> streetName;

   cout << "What is your town? ";
   cin >> town;

   cout << "What is your zip code? ";
   cin >> zipCode;

   cout << "What is your amount donated? ";
   cin >> amtDonated;

   cout << endl;
}

void update(string &lastName, string &firstName, int &age, int &streetNum, string &streetName, string &town, string &zipCode) {
   cout << "What is your last name? ";
   cin >> lastName;

   cout << "What is your first name? ";
   cin >> firstName;

   cout << "What is your age? ";
   cin >> age;

   cout << "What is your street number? ";
   cin >> streetNum;

   cout << "What is your street name? ";
   cin >> streetName;

   cout << "What is your town? ";
   cin >> town;

   cout << "What is your zip code? ";
   cin >> zipCode;

   cout << endl;
}

void view(string &lastName, string &firstName, int &age, int &streetNum, string &streetName, string &town, string &zipCode, float &amtDonated) {
   cout << "Donor Info: " << endl;

   cout << firstName << " " << lastName << ": age " << age << endl;

   cout << streetNum<< " " << streetName << endl;

   cout << town << " " << zipCode << endl;

   cout << "Current Amount Donated: $" << setprecision(2) << fixed << amtDonated << "\n\n";
}

void donate(float &amtDonated) {
   float donation;
   cout << "Enter Amount to Donate: ";
   cin >> donation;
   amtDonated += donation;
   cout << "$" << amtDonated << " donated." << endl;
}

void report(string &lastName, float &amtDonated) {
   cout << lastName << " $" << setprecision(2) << fixed << amtDonated << endl;

}
