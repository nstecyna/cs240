#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Voter.h"

using namespace std;

Voter::Voter(string ln, string fn, string u, string p, int a, int sNum, string sName, string t, string zc, float ad) {
   lastName = ln;
   firstName = fn;
   userid = u;
   password = p;
   age = a;
   streetNum = sNum;
   streetName = sName;
   town = t;
   zipCode = zc;
   amtDonated = ad;
}

Voter::Voter() {
   lastName = "";
   firstName = "";
   userid = "";
   password = "";
   age = 0;
   streetNum = 0;
   streetName = "";
   town = "";
   zipCode = "00000";
   amtDonated = 0.0;
}

Voter& Voter::operator= (const Voter & source) {
   if (this != &source) {
     lastName = source.lastName;
     firstName = source.firstName;
     userid = source.userid;
     password = source.password;
     age = source.age;
     streetNum = source.streetNum;
     streetName = source.streetName;
     town = source.town;
     zipCode = source.zipCode;
     amtDonated = source.amtDonated;
      // check for self copy
   //free heap space used by left hand operand
   //copy all non-heap data members using =
   //allocate new heap space for the left hand operand
   //copy data stored in source's heap memory
   //to left hand operand's heap memory
   }
   return *this;
}

string Voter::getLastName() {
   return lastName;
}

string Voter::getFirstName() {
   return firstName;
}

string Voter::getUserid() {
   return userid;
}

string Voter::getPassword() {
   return password;
}

int Voter::getAge() {
   return age;
}

int Voter::getStreetNum() {
   return streetNum;
}

string Voter::getStreetName() {
   return streetName;
}

string Voter::getTown() {
   return town;
}

string Voter::getZipCode() {
   return zipCode;
}

float Voter::getAmtDonated() {
   return amtDonated;
}

void Voter::update() {
   string inputString = "";
   int inputNum = 0;

   cout << "\nWhat is your last name? ";
   cin >> inputString;
   if (inputString != "") lastName = inputString;

   cout << "\nWhat is your first name? ";
   cin >> inputString;
   if (inputString != "") firstName = inputString;

   cout << "\nWhat is your age? ";
   cin >> inputNum;
   if (inputNum != 0) age = inputNum;

   cout << "\nWhat is your street number? ";
   cin >> inputNum;
   if (inputNum != 0) streetNum = inputNum;

   cout << "\nWhat is your street name? ";
   cin >> inputString;
   if (inputString != "") streetName = inputString;

   cout << "\nWhat is your town? ";
   cin >> inputString;
   if (inputString != "") town = inputString;

   cout << "\nWhat is your zip code? ";
   cin >> inputString;
   if (inputString != "") {
     while (!this->zipCodeCheck(inputString)){
        cout << "\nWhat is your zip code? ";
        cin >> inputString;
     }
     zipCode = inputString;
   }

   cout << endl;
}

void Voter::passwd() {
   string input = "";
   cout << "\nPlease enter password: ";
   cin >> input;
   if (input == password) {
     cout << "\nPlease confirm password: ";
     cin >> input;
     if (input == password) {
       cout << "\nPlease enter new password: ";
       cin >> input;
       while (!this->passwordCheck(input)){
          cout << "\nWhat is your password? ";
          cin >> input;
       }
       password = input;
     } else {
        cout << "\nIncorrect password." << endl;
     }
   } else {
      cout << "\nIncorrect password." << endl;
   }
}

void Voter::view() {
  cout << "Donor Info: " << endl;

  cout << firstName << " " << lastName << ": age " << age << endl;

  cout << streetNum<< " " << streetName << endl;

  cout << town << " " << zipCode << endl;

  cout << "Current Amount Donated: $" << setprecision(2) << fixed << amtDonated << "\n\n";
}

void Voter::donate() {
   float donation;
      cout << "Enter Amount to Donate: ";
      cin >> donation;
      if (donation + amtDonated > 2700.0) {
         cout << "Cannot donate more than a total of $2,700" << endl;
      } else {
         amtDonated += donation;
         cout << "$" << amtDonated << " donated." << endl;
      }
}

void Voter::report() {
   cout << lastName << " $" << setprecision(2) << fixed << amtDonated << endl;
}

bool Voter::logInAttempt(string u, string p) {
   if (userid == u && password == p) {
      this->loggedIn();
      return true;
   }
   return false;
}

void Voter::loggedIn() {

   bool quit = false;
   string input;

   cout << "\nYou are logged in!" << endl;

   while (!quit) {
      cout<<"What would you like to do? (Update, Passwd, View, Donate, Report, Quit) ";
      cin>>input;

      if (input == "Quit") {
         quit = true;
      } else if (input == "Update") {
         this->update();
      } else if (input == "Passwd") {
         this->passwd();
      } else if (input == "View") {
         this->view();
      } else if (input == "Donate") {
         this->donate();
      } else if (input == "Report") {
         this->report();
      }
   }
}

bool Voter::useridCheck(string s) {
   if (s.size() < 5 || s.size() > 10) {
      cout << "Userid must contain between 5-10 characters.";
      return false;
   }

   for (int i = 0; i < s.size(); i++) {
      if (!isalpha(s.at(i)) && !isdigit(s.at(i))) {
         cout << "Userid must contain only letters and numbers.";
      return false;
      }
   }
   return true;
}

bool Voter::passwordCheck(string s) {
   if (s.size() < 6) {
      cout << "Userid must contain at least 6 characters.";
      return false;
   }

   bool neither = false;
   bool digit = false;

   for (int i = 0; i < s.size(); i++) {
      if (!isalpha(s.at(i)) && !isdigit(s.at(i))) {
         neither = true;
      } else if (isdigit(s.at(i))) {
         digit = true;
      }
   }
   if (neither && digit) return true;
   cout << "Userid must contain at least one digit and one character that is neither a letter nor a digit).";
   return false;
}

bool Voter::zipCodeCheck(string s) {
   if (s.size() != 5) {
      cout << "Userid must contain 5 digits.";
      return false;
   }

   for (int i = 0; i < s.size(); i++) {
      if (!isdigit(s.at(i))) {
         cout << "Userid must contain only digits.";
         return false;
      }
   }
   return true;
}
