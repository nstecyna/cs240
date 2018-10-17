#include <iostream>
#include <stdlib.h>

using namespace std;

class LLC {
    public:

	class Node {
    	    public:
        	string data;
        	Node * next;
        }; 

        Node * first;
        Node * last;

        LLC();
        LLC(const LLC& other);
        void operator=(LLC other);
        ~LLC();
        bool contains(const string & s);
        bool insert(const string & s);
	void remove(const string & s);
	void shuffle();
	LLC operator+(LLC other);
	void head(int n);
	string tail();
	ostream& operator << (const LLC& llc);
	void operator+=(int n);
	int len();
	void join(LLC &other);

	Node * getFirst();
}; 
