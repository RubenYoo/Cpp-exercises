#include "Rectangle.h"

 //this func, return if the rectangle is special or not
bool Rectangle::isSpecial() const
{
	return distance(array[0], array[1]) == distance(array[1], array[2]);
}

//this func, print what the speciality of the rectangle
void Rectangle::printSpecial() const
{
	cout << "Square with side length " << distance(array[0], array[1]) << endl;
}

//this func, return the area of the rectangle
float Rectangle::area() const
{
	return distance(array[0], array[1]) * distance(array[1], array[2]);
}
