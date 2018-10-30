#include <iostream>
#include <stdlib.h>
#include "LLC.h"
#include "PlayingCard.h"

using namespace std;

int main() {
	cout << "Test 1" << endl;
	PlayingCard c1(5,"C");

	cout << "Test 2" << endl;
	PlayingCard c2(13,"C");

	cout << "Test 3" << endl;
	cout << "false : " << (c1 == c2) << endl;

	cout << "Test 4" << endl;
	cout << "false : " << (c1 > c2) << endl;

	cout << "Test 5" << endl;
	cout << "true : " << (c2 > c1) << endl;

	cout << "Test 6" << endl;
	PlayingCard c3(13,"C");
	cout << "true : " << (c2 == c3) << endl;

	cout << "Test 7" << endl;
	cout << "false : " << (c2 > c3) << endl;
	cout << "false : " << (c3 > c2) << endl;

	cout << "Test 7" << endl;
	cout << "5C : " << c1 << endl;
	cout << "KC : " << c2 << endl;
	cout << "KC : " << c3 << endl;


	cout << endl << "====LLC<string> Testing====" << endl << endl;

	cout << "Creating an LLC<string> and testing insert(), head(), and tail()" << endl;
	LLC<string> s1;
	s1.insert("hi");
	s1.head(1);
	s1.tail();
	s1.insert("guy");
	s1.head(2);
	s1.tail();
	s1.insert("you");
	s1.head(3);
	s1.tail();
	s1.insert("look");
	s1.head(4);
	s1.tail();
	s1.insert("fly");
	s1.head(7);
	s1.tail();

	cout << "Creating another LLC<string> and testing insert(), head(), and tail()." << endl;
	LLC<string> s2;
	s2.insert("but");
	s2.head(1);
	s2.tail();
	s2.insert("you're");
	s2.head(2);
	s2.tail();
	s2.insert("a");
	s2.head(3);
	s2.tail();
	s2.insert("spy");
	s2.head(4);
	s2.tail();
	s2.insert("!");
	s2.head(7);
	s2.tail();

	cout << "Testing join()." << endl;
	s1.join(s2);
	s1.head(20);
	s2.head(20);

	cout << "Testing copy constructor." << endl;
	LLC<string> s3(s1);
	s3.head(20);
	s1.head(20);
	s2.head(20);

	cout << "Testing operator=." << endl;
	s3 = s1;
	s3.head(30);
	s1.head(30);
	s2.head(30);

	cout << "s3 contains 'hi': " << s3.contains("hi") << endl;
	cout << "s3 contains 'salty': " << s3.contains("salty") << endl;

	cout << "Testing remove()." << endl;
	s3.remove("you're");
	s3.head(100);

	cout << "Testing operator+." << endl;
	s1.head(100);
	s3.head(100);
	s1 = s1 + s3;
	s1.head(100);
	s3.head(100);

	cout << "Printing s3: " << s3 << endl;

	cout << "Testing operator+=." << endl;
	s3+=3;
	s3.head(100);

	cout << "s3 length: " << s3.len() << endl;

	cout << "Testing shuffle()." << endl;
	s3.shuffle();
	s3.head(100);


	cout << endl << "====LLC<int> Testing====" << endl << endl;

	cout << "Creating an LLC<int> and testing insert(), head(), and tail()" << endl;
	LLC<int> i1;
	i1.insert(1);
	i1.head(1);
	i1.tail();
	i1.insert(2);
	i1.head(2);
	i1.tail();
	i1.insert(5);
	i1.head(3);
	i1.tail();
	i1.insert(4);
	i1.head(4);
	i1.tail();
	i1.insert(3);
	i1.head(7);
	i1.tail();

	cout << "Creating another LLC<int> and testing insert(), head(), and tail()." << endl;
	LLC<int> i2;
	i2.insert(6);
	i2.head(1);
	i2.tail();
	i2.insert(7);
	i2.head(2);
	i2.tail();
	i2.insert(10);
	i2.head(3);
	i2.tail();
	i2.insert(9);
	i2.head(4);
	i2.tail();
	i2.insert(8);
	i2.head(7);
	i2.tail();

	cout << "Testing join()." << endl;
	i1.join(i2);
	i1.head(20);
	i2.head(20);

	cout << "Testing copy constructor." << endl;
	LLC<int> i3(i1);
	i3.head(20);
	i1.head(20);
	i2.head(20);

	cout << "Testing operator=." << endl;
	i3 = i1;
	i3.head(30);
	i1.head(30);
	i2.head(30);

	cout << "i3 contains 'hi': " << i3.contains(1) << endl;
	cout << "i3 contains 'salty': " << i3.contains(35) << endl;

	cout << "Testing remove()." << endl;
	i3.remove(7);
	i3.head(100);

	cout << "Testing operator+." << endl;
	i1.head(100);
	i3.head(100);
	i1 = i1 + i3;
	i1.head(100);
	i3.head(100);

	cout << "Printing i3: " << i3 << endl;

	cout << "Testing operator+=." << endl;
	i3+=3;
	i3.head(100);

	cout << "i3 length: " << i3.len() << endl;

	cout << "Testing shuffle()." << endl;
	i3.shuffle();
	i3.head(100);


	cout << endl << "====LLC<PlayingCard> Testing====" << endl << endl;

	cout << "Creating an LLC<PlayingCard> and testing insert(), head(), and tail()" << endl;
	LLC<PlayingCard> pc1;
	pc1.insert(PlayingCard(1,"C"));
	pc1.head(1);
	pc1.tail();
	pc1.insert(PlayingCard(2,"H"));
	pc1.head(2);
	pc1.tail();
	pc1.insert(PlayingCard(5,"S"));
	pc1.head(3);
	pc1.tail();
	pc1.insert(PlayingCard(4,"D"));
	pc1.head(4);
	pc1.tail();
	pc1.insert(PlayingCard(3,"C"));
	pc1.head(7);
	pc1.tail();

	cout << "Creating another LLC<PlayingCard> and testing insert(), head(), and tail()." << endl;
	LLC<PlayingCard> pc2;
	pc2.insert(PlayingCard(5,"C"));
	pc2.head(1);
	pc2.tail();
	pc2.insert(PlayingCard(6,"H"));
	pc2.head(2);
	pc2.tail();
	pc2.insert(PlayingCard(10,"D"));
	pc2.head(3);
	pc2.tail();
	pc2.insert(PlayingCard(9,"S"));
	pc2.head(4);
	pc2.tail();
	pc2.insert(PlayingCard(8,"C"));
	pc2.head(7);
	pc2.tail();

	cout << "Testing join()." << endl;
	pc1.join(pc2);
	pc1.head(20);
	pc2.head(20);

	cout << "Testing copy constructor." << endl;
	LLC<PlayingCard> pc3(pc1);
	pc3.head(20);
	pc1.head(20);
	pc2.head(20);

	cout << "Testing operator=." << endl;
	pc3 = pc1;
	pc3.head(30);
	pc1.head(30);
	pc2.head(30);

	cout << "pc3 contains 'hi': " << pc3.contains(PlayingCard(1,"C")) << endl;
	cout << "pc3 contains 'salty': " << pc3.contains(PlayingCard(66,"C")) << endl;

	cout << "Testing remove()." << endl;
	pc3.remove(PlayingCard(10,"D"));
	pc3.head(100);

	cout << "Testing operator+." << endl;
	pc1.head(100);
	pc3.head(100);
	pc1 = pc1 + pc3;
	pc1.head(100);
	pc3.head(100);

	cout << "Printing pc3: " << pc3 << endl;

	cout << "Testing operator+=." << endl;
	pc3+=3;
	pc3.head(100);

	cout << "pc3 length: " << pc3.len() << endl;

	cout << "Testing shuffle()." << endl;
	pc3.shuffle();
	pc3.head(100);
}
