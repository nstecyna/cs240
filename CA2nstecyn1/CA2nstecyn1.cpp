#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "VoterDB.h"

using namespace std;

// int main(int argc, char **argv) {
// //    string progName(argv[0]);
// //    cout << endl << "Argc is an integer containing the number of arguments, " << endl;
// //    cout << "including the program name itself. " << endl << endl;
// //    cout << "This program contains " << argc << " argument(s)." << endl << endl;
// //    cout << "You ran this program with " << progName << endl;
// //    cout << "The other arguments are: " << endl;
// for (int i=1; i<argc; i++)
//    cout << "argv[" << i << "]: " << argv[i] << endl;
// // One "C++" way to convert the C-style string in argv[1] into an int
// // Don't forget to #include <sstream>
// if (argc > 1) {
//
//
// }
// return 0;
// }

int main(int argc, char **argv) {
   int num1 = 25;

   if (argc > 1) {
      istringstream buf(argv[1]); // create an input string stream
      buf >> num1; // use the extraction operator
   }

   VoterDB db = VoterDB(num1);

   if (argc > 2) {
      db.load(argv[2]);
   }

   cout<<db.getCapacity()<<" Voters."<<endl;

   bool quit = false;
   string input;

   while (!quit) {
      cout<<"\nWhat would you like to do? (Login, New, Report, Save, Load, Quit) ";
      cin>>input;

      if (input == "Quit") {
         quit = true;
      } else if (input == "Login") {
         db.login();
      } else if (input == "New") {
         if (db.getNumVoters() == db.getCapacity()) {
            cout << "There is no more room for new voters!" << endl;
         } else {
            db.newVoter();
        }
      } else if (input == "Report") {
         db.report();
      } else if (input == "Save") {
         db.save();
      } else if (input == "Load") {
         db.load("");
      }
   }
}
