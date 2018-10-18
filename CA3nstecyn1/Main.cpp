#include <iostream>
#include <stdlib.h>
#include "LLC.h"

using namespace std;

int main() {
	cout << "Creating an LLC and testing insert(), head(), and tail()" << endl;
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

	cout << "Creating another LLC and testing insert(), head(), and tail()." << endl;
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

	cout << "Tesing join()." << endl;
	good.join(great);
	good.head(20);
	great.head(20);

	cout << "Testing copy constructor." << endl;
	LLC awesome(good);
	awesome.head(20);
	good.head(20);
	great.head(20);

	cout << "Testing operator=." << endl;
	awesome = good;
	awesome.head(30);
	good.head(30);
	great.head(30);

	cout << "Awesome contains 'hi': " << awesome.contains("hi") << endl;
	cout << "Awesome contains 'salty': " << awesome.contains("salty") << endl;

	cout << "Testing remove()." << endl;
	awesome.remove("you're");
	awesome.head(100);

	cout << "Testing operator+." << endl;
	good.head(100);
	awesome.head(100);
	good = good + awesome;
	good.head(100);
	awesome.head(100);

	cout << "Printing awesome: " << awesome << endl;

	cout << "Testing operator+=." << endl;
	awesome+=3;
	awesome.head(100);

	cout << "Awesome length: " << awesome.len() << endl;

	cout << "Testing shuffle()." << endl;
	awesome.shuffle();
	awesome.head(100);
}
