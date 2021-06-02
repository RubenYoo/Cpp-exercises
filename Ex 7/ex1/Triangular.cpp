#include "Triangular.h"
#include <cmath>

 //this func, return if the triangle is special or not
bool Triangular::isSpecial() const
{
	return distance(array[0], array[1]) == distance(array[1], array[2]) && distance(array[0], array[1]) == distance(array[0], array[2]);
}

//this func, print what the speciality of the triangle
void Triangular::printSpecial() const
{
	cout << "An isosceles triangle with a side length " << distance(array[0], array[1]) << endl;
}

//this func, return the area of the triangle
float Triangular::area() const
{
	float a = distance(array[0], array[1]);
	float b = distance(array[1], array[2]);
	float c = distance(array[0], array[2]);
	
	float s = (a + b + c) / 2;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}
