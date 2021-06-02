#include <iostream>
#include "Metsoula.h"
using namespace std;

int main() {

	int  num;                                                        //declaring a variable

	cout << "enter number of sides:" << endl;
	cin >> num;                                                      //reading the num sides of the 1's polygon
	Metsoula polygon1(num);                                          //creating the polygon

	cout << "enter number of sides:" << endl;
	cin >> num;                                                      //reading the num sides of the 2's polygon
	Metsoula polygon2(num);                                          //creating the polygon

	if (polygon1.equal(polygon2))                                    //check if the two polygon are equal
	{
		cout << "equal.perimeter:" << polygon1.ekef() << endl;       //print the perimeter of one of them
	}
	else                                                             //if not equal
	{                                                          
		cout << "perimeter:" << polygon1.ekef() << endl;             //print the perimeter
		cout << "perimeter:" << polygon2.ekef() << endl;             //of the two polygons
	}

	return 0;
}
/*
enter number of sides:
4
in constructor
enter the point values:
(0,0) (0,2) (2,2) (2,0)
enter number of sides:
3
in constructor
enter the point values:
(1,1) (2,0) (3,1)
in copy-constructor
in destructor
perimeter: 8
perimeter: 5
in destructor
in destructor
*/
