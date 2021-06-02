#include "Shape.h"
#include <iostream>
#include <cmath>
using namespace std;

//constructor
Shape::Shape(int num)
{
	if (num < 0)
		throw "ERROR\n";

	numOfPoints = num;
	array = new Point[num];				//creating a shape with "num" points

	cout << "Enter values of " << num << " points: " << endl;

	for (int i = 0; i < num; i++)
	{
		cin >> array[i];				//reading the points
	}
}

//copy contructor
Shape::Shape(const Shape& sh)
{
	if (numOfPoints)
		delete[] array;

	array = new Point[sh.numOfPoints];
	numOfPoints = sh.numOfPoints;

	for (int i = 0; i < numOfPoints; i++)
	{
		array[i] = sh.array[i];
	}
}

//move constructor
Shape::Shape(const Shape&& sh)
{
	if (numOfPoints)
		delete[] array;

	array = new Point[sh.numOfPoints];
	numOfPoints = sh.numOfPoints;

	for (int i = 0; i < numOfPoints; i++)
	{
		array[i] = sh.array[i];
	}
}

//destructor
Shape::~Shape()
{
	if (numOfPoints)
		delete[] array;
}

//this func, receive two Points objects, and return the distance between them
float Shape::distance(Point& p1,Point& p2) const
{
	return (sqrt(pow((p1.getX() - p2.getX()), 2) + pow((p1.getY() - p2.getY()), 2)));
}

//operator <<
ostream& operator<<(ostream& os, const Shape& sh)
{
	cout << "points: ";

	for (int i = 0; i < sh.numOfPoints; i++)
	{
		cout << '(' << sh.array[i].getX() << ',' << sh.array[i].getY() << ") ";
	}

	return os;
}
