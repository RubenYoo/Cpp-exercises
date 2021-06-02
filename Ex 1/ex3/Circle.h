#pragma once
#include "Point.h"
class Circle
{
	//declaring the private variables of the class
private:
	Point center;
	int radius;
	//declaring the public prototypes of the class
public:
	void setCenter(int x, int y);
	void setRadius(int myRadius);
	Point getCenter();
	int getRadius();
	float area();
	float perimeter();
	int onInOut(Point p);
};
