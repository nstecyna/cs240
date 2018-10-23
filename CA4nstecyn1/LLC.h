#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class LLC {
    public:

	class Node {
    	    public:
        	T data;
        	Node * next;
        }; 

        Node * first;
        Node * last;

        LLC();
        LLC(const LLC<T>& other);
        LLC<T>& operator=(const LLC<T> &other);
        ~LLC();
        bool contains(const T & s);
        bool insert(const T & s);
	void remove(const T & s);
	void shuffle();
	LLC<T> operator+(const LLC<T> &other);
	void head(int n);
	T tail();
	friend ostream& operator << (ostream & out, const LLC<T>& llc);
	void operator+=(int n);
	int len();
	void join(const LLC<T> &other);
}; 
