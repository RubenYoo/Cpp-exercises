#include "Point.h"
#include <iostream>
using namespace std;

//this func, receive a num and set it to the variable x
void Point::setX(int myX)
{
	x = myX;
}

//this func, receive a num and set it to the variable y
void Point::setY(int myY)
{
	y = myY;
}

//this func, return the variable x
int Point::getX()
{
	return x;
}

//this func, return the variable y
int Point::getY()
{
	return y;
}

//operator >>
istream& operator>>(istream& is, Point& p)
{
	char tav;
	cin >> tav >> p.x >> tav >> p.y >> tav;

	return is;
}
