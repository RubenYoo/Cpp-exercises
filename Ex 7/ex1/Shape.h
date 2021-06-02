#pragma once
#include "Point.h"

class Shape
{
protected:
	//variables
	int	numOfPoints;
	Point *array;

public:
	//constructors
	Shape() : numOfPoints(0), array(nullptr) {}
	Shape(int);
	//copy-constructor
	Shape(const Shape&);
	//move-constructor
	Shape(const Shape&&);
	//destructor
	virtual ~Shape();
	//operator
	friend ostream& operator<<(ostream& os, const Shape& sh);
	//method
	float distance(Point&, Point&) const;
	//virtual methods
	virtual float area() const = 0;
	virtual bool isSpecial() const = 0 ;
	virtual void printSpecial() const = 0 ;
};

