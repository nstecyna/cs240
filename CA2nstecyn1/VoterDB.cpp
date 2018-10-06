#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "VoterDB.h"

using namespace std;

VoterDB::VoterDB (int maxSize) {
   numVoters = 0;
   capacity = maxSize;
   voters = new Voter [maxSize];
   assert (voters != nullptr);
}

VoterDB::~VoterDB() {
     delete []voters;
}

int VoterDB::getNumVoters() {
   return numVoters;
}

int VoterDB::getCapacity() {
   return capacity;
}

void VoterDB::newVoter() {
   string lastName;
   string firstName;
   string userid;
   string password;
   int age;
   int streetNum;
   string streetName;
   string town;
   string zipCode;

   cout << "What is your last name? ";
   cin >> lastName;

   cout << "What is your first name? ";
   cin >> firstName;

   cout << "What is your userid? ";
   cin >> userid;
   while (!voters[numVoters].useridCheck(userid)){
      cout << "What is your userid? ";
      cin >> userid;
   }

   cout << "What is your password? ";
   cin >> password;
   while (!voters[numVoters].passwordCheck(password)){
      cout << "What is your password? ";
      cin >> password;
   }

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
   while (!voters[numVoters].zipCodeCheck(zipCode)){
      cout << "What is your zip code? ";
      cin >> zipCode;
   }

   voters[numVoters] = Voter(lastName, firstName, userid, password, age,
      streetNum, streetName, town, zipCode, 0.0);
   numVoters++;
}

void VoterDB::login(){
   string u = "";
   string p = "";

   cout << "What is your userid? ";
   cin >> u;

   cout << "What is your password? ";
   cin >> p;

   bool found = false;
   for (int i = 0; i < numVoters; i++) {
      if (voters[i].logInAttempt(u,p)) {
         found = true;
      }
   }

   if (!found) {
      cout << "Incorrect userid or password." << endl;
   }
}

void VoterDB::report() {
  float donations = 0.0;
  for (int i = 0; i < numVoters; i++) {
     donations += voters[i].getAmtDonated();
  }
   cout << "There are " << numVoters << " voters in the database and $" <<
      setprecision(2) << fixed << donations <<
      " has been donated to the campaign." << endl;
}

void VoterDB::save() {
   string fn;
   string overwrite = "n";

   cout << "Enter a filename: ";
   cin >> fn;
   ifstream testfile (fn);

   while (overwrite == "n") {
      if (testfile.is_open()) {
         cout << "This file already exists. Would you like to overwrite it? (y/n): ";
         cin >> overwrite;
         if (overwrite == "n") {
            cout << "Enter a filename: ";
            cin >> fn;
            ifstream testfile (fn);
         }

      } else overwrite = "y";
   }

   testfile.close();
   ofstream myfile (fn);

   if (myfile.is_open()) {
      for (int i = 0; i < numVoters; i++) {
         myfile << "next" << endl;
         myfile << voters[i].getLastName() << endl;
         myfile << voters[i].getFirstName() << endl;
         myfile << voters[i].getUserid() << endl;
         myfile << voters[i].getPassword() << endl;
         myfile << voters[i].getAge() << endl;
         myfile << voters[i].getStreetNum() << endl;
         myfile << voters[i].getStreetName() << endl;
         myfile << voters[i].getTown() << endl;
         myfile << voters[i].getZipCode() << endl;
         myfile << setprecision(2) << fixed << voters[i].getAmtDonated() << endl;
      }
      myfile.close();
      cout << "Saved voters to file!" << endl;
   } else cout << "Unable to open file.";
}

void VoterDB::load(string fn) {
   if (fn == "") {
     cout << "Enter a filename: ";
     cin >> fn;
   }
   string line;
   ifstream myfile (fn);
   if (myfile.is_open())
   {
      string lastName;
      string firstName;
      string userid;
      string password;
      int age;
      int streetNum;
      string streetName;
      string town;
      string zipCode;
      float amtDonated;

      getline(myfile,line);

      while (numVoters < capacity && line == "next") {
         getline(myfile,line);
         lastName = line;
         getline(myfile,line);
         firstName = line;
         getline(myfile,line);
         userid = line;
         getline(myfile,line);
         password = line;
         getline(myfile,line);
         istringstream a(line);
         a >> age;
         getline(myfile,line);
         istringstream sN(line);
         sN >> streetNum;
         getline(myfile,line);
         streetName = line;
         getline(myfile,line);
         town = line;
         getline(myfile,line);
         zipCode = line;
         getline(myfile,line);
         istringstream aD(line);
         aD >> amtDonated;
         getline(myfile,line);

         voters[numVoters] = Voter(lastName, firstName, userid, password, age,
            streetNum, streetName, town, zipCode, amtDonated);

         numVoters++;
      }

      myfile.close();
      cout << "Loaded voters from file!" << endl;
   } else cout << "Unable to open file." << endl;
}
