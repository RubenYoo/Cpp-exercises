#pragma once
#include <iostream>
using namespace std;

class Point
{
	//declaring the private variables of the class
private:
	int x;
	int y;
	//declaring the public prototypes of the class
public:
	//set and get methods
	void setX(int myX);
	void setY(int myY);
	int getX();
	int getY();

	//operator
	friend istream& operator>>(istream& is, Point& p);
};
