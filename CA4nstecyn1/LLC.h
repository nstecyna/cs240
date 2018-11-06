#include <iostream>
#include <stdlib.h>
#include <cstdlib>

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
		template <class U>
		friend ostream& operator << (ostream & out, const LLC<U>& llc);
		void operator+=(int n);
		int len();
		void join(const LLC<T> &other);
		T takeFirstElement();
		void empty();
};

template <class T>
LLC<T>::LLC() {
    first = nullptr;
    last = nullptr;
    srand(time(0));
}

template <class T>
LLC<T>::LLC(const LLC<T>& other) {
    first = nullptr;
    last = nullptr;
    Node * temp = other.first;
    while (temp != nullptr) {
	this->insert(temp->data);
	temp = temp->next;
    }
}

template <class T>
LLC<T>& LLC<T>::operator=(const LLC<T> &other) {
    this->~LLC();

    first = nullptr;
    last = nullptr;
    this->join(other);

    return *this;
}

template <class T>
LLC<T>::~LLC() {
    Node * temp  = first;
    while (temp != nullptr) {
	first = temp->next;
	delete temp;
	temp = first;
    }
}

template <class T>
bool LLC<T>::contains(const T & s) {
    Node * temp = first;
    while (temp != nullptr) {
	if (temp->data == s) return true;
	temp = temp->next;
    }
    return false;
}

template <class T>
bool LLC<T>::insert(const T & s) {
    Node * temp = new Node;
    temp->data = s;
    temp->next = nullptr;

    if (first == nullptr) {
    	first = temp;
    	last = temp;
      return true;
    } else {
    	last->next = temp;
    	last = temp;
      return true;
    }
    return false;
}

template <class T>
void LLC<T>::remove(const T & s) {
    Node * temp = first;
    Node * prev = nullptr;
    while (temp != nullptr) {
	if (temp->data == s && prev == nullptr) {
	    first = temp->next;
            prev = temp;
	    temp = prev->next;
	    delete prev;
	} else if (temp->data == s) {
	    prev->next = temp->next;
    	    delete temp;
	    temp = prev->next;
	    if (temp == nullptr) last = prev;
        } else {
	    prev = temp;
	    temp = temp->next;
	}
    }
}

template <class T>
void LLC<T>::shuffle() {
  T s;
	Node * prev = first;
	Node * curr = first->next;
  for (int i = 0; i < rand() % 20; i++) {
	while (curr != nullptr) {
	    s = curr->data;
	    curr->data = prev->data;
	    prev->data = s;
	    prev = curr;
	    curr = prev->next;
	}
    }
}

template <class T>
LLC<T> LLC<T>::operator+(const LLC<T> &other) {
    LLC<T> ret = *this;
    ret.join(other);
    return ret;
}

template <class T>
void LLC<T>::head(int n) {
    Node * temp = first->next;
    int i = 0;
    cout << "[" << first->data;
    while (temp != nullptr and i < n) {
    	cout << ", " << temp->data;
    	temp = temp->next;
    	i++;
    }
    cout << "]" << endl;
}

template <class T>
T LLC<T>::tail() {
    cout << last->data << endl;
    return last->data;
}

template <class U>
ostream& operator << (ostream & out, const LLC<U>& llc) {
    if (llc.first == nullptr) {
      out << "[NULL]";
    } else {
      typename LLC<U>::Node * temp = llc.first->next;
      out << "[" << llc.first->data;
      while (temp != nullptr) {
      	out << ", " << temp->data;
      	temp = temp->next;
      }
      out << "]";
    }

    return out;
}

template <class T>
void LLC<T>::operator+=(int n) {
    Node * temp = first;
    n = n % len();
    for (int i = 0; i < n; i++) {
  	temp = temp->next;
  }
  last->next = first;
  first = temp->next;
  temp->next = nullptr;
}

template <class T>
int LLC<T>::len() {
    Node * temp = first;
    int i = 0;
    while (temp != nullptr) {
	i++;
        temp = temp->next;
    }
    return i;
}

template <class T>
void LLC<T>::join(const LLC<T> &other) {
    Node * temp = other.first;
    while (temp != nullptr) {
	insert(temp->data);
	temp = temp->next;
    }
}

template <class T>
T LLC<T>::takeFirstElement() {
    T data = first->data;
    Node * temp = first;
    first = first->next;
    delete temp;
    return data;
}

template <class T>
void LLC<T>::empty() {
	Node * temp;
	while (temp != nullptr) {
		temp = first->next;
		delete first;
		first = temp;
	}
	last = nullptr;
}
