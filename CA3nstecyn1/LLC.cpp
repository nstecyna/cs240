#include <iostream>
#include <stdlib.h>
#include "LLC.h"

using namespace std;

LLC::LLC() {
    first = nullptr;
    last = nullptr;
}

LLC::LLC(const LLC& other) {
    first = nullptr;
    last = nullptr;
    Node * temp = other.first;
    while (temp != nullptr) {
	this->insert(temp->data);
	temp = temp->next;
    }
}

LLC& LLC::operator=(const LLC &other) {
    this->~LLC();

    first = nullptr;
    last = nullptr;
    this->join(other);

    return *this;
}

LLC::~LLC() {
    Node * prev = first;
    Node * current = first->next;
    while (current != nullptr) {
	delete prev;
	prev = current;
	current = current->next;
    }
    delete prev;
}

bool LLC::contains(const string & s) {
    Node * temp = first;
    while (temp != nullptr) {
	if (temp->data == s) return true;
	temp = temp->next;
    }
    return false;
}

bool LLC::insert(const string & s) {
    Node * temp = new Node;
    temp->data = s;
    temp->next = nullptr;

    if (first == nullptr) {
	first = temp;
	last = temp;
    } else {
	last->next = temp;
	last = temp;
    }
}

void LLC::remove(const string & s) {
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

void LLC::shuffle() {
    if (first->next->next == nullptr) {
	last = first;
	first = last->next;
	first->next = last;
	last->next = nullptr;
    } else {
	Node * prev = first;
	Node * curr = first->next;
	string s;
	while (curr != nullptr) {
	    s = curr->data;
	    curr->data = prev->data;
	    prev->data = s;
	    prev = curr;
	    curr = prev->next;
	}
    }
}

LLC LLC::operator+(const LLC &other) {
    LLC ret = *this;
    ret.join(other);
    return ret;
}

void LLC::head(int n) {
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

string LLC::tail() {
    cout << last->data << endl;
    return last->data;
}

ostream& operator << (ostream & out, const LLC& llc) {
    LLC::Node * temp = llc.first->next;
    int i = 0;
    out << "[" << llc.first->data;
    while (temp != nullptr) {
	out << ", " << temp->data;
	temp = temp->next;
    }
    out << "]";

    return out;
}

void LLC::operator+=(int n) {
    Node * temp = first;
    for (int i = 0; i < n; i++) {
	if (temp->next->next == nullptr) break;
	temp = temp->next;
    }
    last->next = first;
    first = temp->next;
    temp->next = nullptr;
}

int LLC::len() {
    Node * temp = first;
    int i = 0;
    while (temp != nullptr) {
	i++;
        temp = temp->next;
    }
    return i;
}

void LLC::join(const LLC &other) {
    Node * temp = other.first;
    while (temp != nullptr) {
	insert(temp->data);
	temp = temp->next;
    }
}
