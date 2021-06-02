#include "Circle.h"
#include <cmath>

//const of PI
const float PI = 3.14;

//this func, return if the circle is special or not
bool Circle::isSpecial() const
{
	return array[0].getX() == array[0].getY();
}

//this func, print what the speciality of the circle
void Circle::printSpecial() const
{
	cout << "A canonical circle with a radius " << radius << endl;
}

//this func, return the area of the circle
float Circle::area() const
{
	return pow(radius, 2) * PI;
}
