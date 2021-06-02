#include "Vector.h"
#include <iostream>
using namespace std;

enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast, at, insert
};

int main()
{
	Vector  v1(10), v2(10), v3;                  //declaring 3 Vectors

	for (int i = 1; i <= 4; i++)                 //entering values into 2 Vectors
	{
		v1.insert(i);
		v2.insert(i + 4);
	}

	int choice, val, index;                      //declaring variables

	cout << "enter your choice 0-8:\n";
	cin >> choice;

	while (choice)                               //if choice is not equal to 0, enter
	{
		switch (choice)
		{
			//copy Vector 1 to Vector 2
		case assignment: v3.assign(v1);
			break;
			//check if Vector 1 is equal or not to Vector 2
		case isEqual:	if (v1.isEqual(v2)) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
			//print the multiplication of Vector 1 and Vector 2
		case mult:		cout << "v1*v2=" << v1.strcatcat(v2) << endl;
			break;
			//add to Vector 3, Vector 1 and 2
		case add:		v3.assign(v1.strnewcat(v2));
			break;
			//clear Vector 1
		case clear:		v1.clear();
			break;
			//delete last value of Vector 2
		case delLast:	v2.delLast();
			break;
			//change a value in a specific index in Vector 3
		case at:		cout << "enter index:" << endl; cin >> index; cout << "enter value:" << endl; cin >> val; v3.at(index) = val;
			break;
			//add a value into Vector 3
		case insert:	cout << "enter value:" << endl; cin >> val; v3.insert(val);
			break;
		default: cout << "ERROR";
		}

		v1.print();		v2.print();		v3.print();                  //print all the 3 Vectors
		cout << "enter your choice 0-8:\n";
		cin >> choice;
	}
	return 0;
}
/*
enter your choice 0-8:
4
capacity: 10 size: 4 values: 1 2 3 4
capacity: 10 size: 4 values: 5 6 7 8
capacity: 20 size: 8 values: 1 2 3 4 5 6 7 8
enter your choice 0-8:
0
*/
