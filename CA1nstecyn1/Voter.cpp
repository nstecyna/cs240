#include <iostream>
#include <stdlib.h>
#include "VoterDB.h"

using namespace std;

int main(int argc, char *argv[]) {
   string lastName = "[empty]";
   string firstName = "[empty]";
   int age = -1;
   int streetNum = 0;
   string streetName = "[empty]";
   string town = "[empty]";
   string zipCode = "-----";
   float amtDonated = 0;
   // lastName, firstName, age, streetNum, streetName, town, zipCode, amtDonated

   bool quit = false;
   string input;

   while (!quit) {
      cout<<"\nEnter a command.\nChoose from [\"New\" \"Update\" \"View\" \"Donate\" \"Report\" \"Quit\"]\n:";
      cin>>input;

      if (input == "quit") {
         quit = true;
      } else if (input == "new") {
         newVoter(lastName, firstName, age, streetNum, streetName, town, zipCode, amtDonated);
      } else if (input == "update") {
         update(lastName, firstName, age, streetNum, streetName, town, zipCode);
      } else if (input == "view") {
         view(lastName, firstName, age, streetNum, streetName, town, zipCode, amtDonated);
      } else if (input == "donate") {
         donate(amtDonated);
      } else if (input == "report") {
         report(lastName, amtDonated);
      }
   }
}
