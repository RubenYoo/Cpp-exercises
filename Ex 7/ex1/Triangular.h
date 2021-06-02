#pragma once
#include "Shape.h"

class Triangular : public Shape
{
public:
	//constructor
	Triangular() : Shape(3) {}

	//methods
	virtual bool isSpecial() const;
	virtual void printSpecial() const;
	virtual float area() const;
};

