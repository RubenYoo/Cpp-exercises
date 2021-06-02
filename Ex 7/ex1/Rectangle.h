#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	//contructor
	Rectangle() : Shape(4) {}

	//methods
	virtual bool isSpecial() const;
	virtual void printSpecial() const;
	virtual float area() const;
};

