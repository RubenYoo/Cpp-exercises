#include "Circle.h"
#include <iostream>
using namespace std;

int main() {

	//declaring all the variables
	Circle circle1, circle2, circle3;
	Point point;
	char tav;
	int x, y, r;
	int a = 0, b = 0, c = 0;

	cout << " enter the center point and radius of 3 circles:" << endl;

	//reading the 3 center and radius od the circles

	cin >> tav >> x >> tav >> y >> tav >> r;
	circle1.setCenter(x, y), circle1.setRadius(r);

	cin >> tav >> x >> tav >> y >> tav >> r;
	circle2.setCenter(x, y), circle2.setRadius(r);

	cin >> tav >> x >> tav >> y >> tav >> r;
	circle3.setCenter(x, y), circle3.setRadius(r);
	
	//printing the perimeter of the 3 circle
	cout << "perimeter: A: " << circle1.perimeter() << " B: " << circle2.perimeter() <<
		" C: " << circle3.perimeter() << endl;

	//printing the area of the 3 circle
	cout << "area:     :  A: " << circle1.area() << " B: " << circle2.area() << " C: " << circle3.area()
		<< endl;

	cout << "enter points until (0,0):" << endl;
	
	x = 0, y = 0;
	cin >> tav >> x >> tav >> y >> tav;                    //reading a point

	while (x || y)
	{
		point.setX(x);
		point.setY(y);
		
		//checking if the point is in the 3 circle
		if (circle1.onInOut(point) != 1)
			a++;
		if (circle2.onInOut(point) != 1)
			b++;
		if (circle3.onInOut(point) != 1)
			c++;

		cin >> tav >> x >> tav >> y >> tav;
	}

	//printing how much entered points are in the 3 circles
	cout << "num of points in circle: A: " << a << " B: " << b << " C: " << c;

	return 0;
}
/*
enter the center pointand radius of 3 circles:
(0, 0) 3
(1, 1) 2
(5, 5) 2
perimeter : A : 18.84	B : 12.56	C : 12.56
area : A : 28.26	B : 12.56	C : 12.56
enter points until(0, 0) :
	(0, 1)
	(1, 0)
	(0, 4)
	(0, 0)
	num of points in circle : A:2	B : 2	 C : 0
*/
