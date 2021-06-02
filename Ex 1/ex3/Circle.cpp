#include "Circle.h"
#include <cmath>

//declaring a const num 
const float PI = 3.14;

//this func, receive 2 num, and set them into a "point"
void Circle::setCenter(int x, int y)
{
	center.setX(x);
	center.setY(y);
}

//this func, receive a num and set it to be the radius if the num is valid
void Circle::setRadius(int myRadius)
{
	if (myRadius > 0)
		radius = myRadius;
}

//this func, return a "point"
Point Circle::getCenter()
{
	return center;
}

//this func, return the radius
int Circle::getRadius()
{
	return radius;
}

//this func, calculate and return the area of a circle
float Circle::area()
{
	return PI*std::pow(radius,2);
}

//this func, calculate the perimeter of a circle and return it
float Circle::perimeter()
{
	return PI*2*radius;
}

//this func, receive a Point object and check if the Point object is in
//or out of a circle, and return a num to tell if the Point is in or out
int Circle::onInOut(Point p)
{
	if (pow((p.getX() - center.getX()), 2) + pow((p.getY() - center.getY()), 2) == pow(radius, 2))
		return 0;
	else if(sqrt( pow((p.getX() - center.getX()), 2) + pow((p.getY() - center.getY()), 2)) < radius)
		return -1;
	return 1;
}
