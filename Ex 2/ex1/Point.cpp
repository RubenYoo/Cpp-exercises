#include "Point.h"
#include <cmath>

//this func, receive a num and set it to x
void Point::setX(int myX)
{
	x = myX;
}

//this func; receive a num a set it to y
void Point::setY(int myY)
{
	y = myY;
}

//this func, return x
int Point::getX() const
{
	return x;
}

//this func, return y
int Point::getY() const
{
	return y;
}

//this func, receive a Point object, and return
//this distance between the current Point and the Point
float Point::distance(Point point2)
{
	return sqrt(pow(x - point2.x, 2) + pow(y - point2.y, 2));
}
