#include <iostream>
#include <stdlib.h>

using namespace std;

class Voter {

   public:
      Voter();
      Voter(string lastName, string firstName, string userid, string password, int age, int streetNum, string streetName, string town, string zipCode, float amtDonated);
      Voter& operator= (const Voter & source);
      string getLastName();
      string getFirstName();
      string getUserid();
      string getPassword();
      int getAge();
      int getStreetNum();
      string getStreetName();
      string getTown();
      string getZipCode();
      float getAmtDonated();
      void passwd();
      void update();
      void view();
      void donate();
      void report();
      bool logInAttempt(string u, string p);

      bool useridCheck(string s);
      bool passwordCheck(string s);
      bool zipCodeCheck(string s);

   private:
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

      void loggedIn();
};
