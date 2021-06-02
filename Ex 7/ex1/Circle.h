#pragma once
#include "Shape.h"

class Circle : public Shape
{
	//variable
	float radius;
public:
	//constructor
	Circle(int rad) : radius(rad), Shape(1) {}

	//methods
	virtual bool isSpecial() const;
	virtual void printSpecial() const;
	virtual float area() const;
};

