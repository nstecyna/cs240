#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Voter.h"

using namespace std;

class VoterDB {

   public:
      VoterDB(int maxSize);
      ~VoterDB();
      int getNumVoters();
      int getCapacity();
      void login();
      void newVoter();
      void report();
      void save();
      void load(string fn);

   private:
      int numVoters;
      int capacity;
      Voter * voters;
};
