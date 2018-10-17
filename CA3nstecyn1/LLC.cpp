#include <iostream>
#include <stdlib.h>
#include "LLC.h"

using namespace std;

LLC::LLC() {
    first = nullptr;
    last = nullptr;
}

LLC::LLC(const LLC& other) {
    LLC copy;
    Node * temp = other.first;
    while (temp != nullptr) {
	copy.insert(temp->data);
	temp = temp->next;
    }
}

void LLC::operator=(LLC other) {
    Node * orig = other.first;
    
    while (orig != nullptr) {
	insert(orig->data);
	orig = orig->next;
    }
    
    Node * prev = other.first;
    Node * current = other.first->next;
    while (current != nullptr) {
	delete prev;
	prev = current;
	current = current->next;
    }
    delete prev;
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
    Node * prev;
    while (temp != nullptr) {
	if (temp->data == s) {
	    prev->next = temp->next;
	    delete temp;
	    Node * temp = prev->next;
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
	Node * three = first->next->next;
	Node * one = first;
	Node * prev = nullptr;
	Node * next = three->next;
	first = three;
	while (three != nullptr) {
	    three = one;
	    one = three->next->next;
	    one->next = three;
	    three->next = next;
	    prev->next = one;

	    Node * three = three->next;
	    Node * prev = one;
	    Node * one = one->next;
	    Node * next = three->next;
	}
	last = one->next;
    }
}

LLC LLC::operator+(LLC other) {
    LLC ret = other;
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
    out << "]" << endl;

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

void LLC::join(LLC &other) {
    Node * temp = other.first;
    while (temp != nullptr) {
	insert(temp->data);
	temp = temp->next;
    }
}

int main() {
    LLC good;
    good.insert("hi");
    good.head(1);
    good.tail();
    good.insert("guy");
    good.head(2);
    good.tail();
    good.insert("you");
    good.head(3);
    good.tail();
    good.insert("look");
    good.head(4);
    good.tail();
    good.insert("fly");
    good.head(7);
    good.tail();

    LLC great;
    great.insert("but");
    great.head(1);
    great.tail();
    great.insert("you're");
    great.head(2);
    great.tail();
    great.insert("a");
    great.head(3);
    great.tail();
    great.insert("spy");
    great.head(4);
    great.tail();
    great.insert("!");
    great.head(7);
    great.tail();

    good.join(great);
    good.head(20);
    great.head(20);

    LLC awesome = good;
    awesome.head(20);
    good.head(20);
    great.head(20);
}
