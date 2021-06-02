#pragma once
#include "Point.h"

class Metsoula
{
	//private variables of the class
	Point *p;
	int size;
public:
	Metsoula(int a = 0);                               //constructor
	Metsoula(const Metsoula &object);                  //copy constructor
	~ Metsoula();                                      //destructor
	//methods of the class
	int getSize() const;
	void addPoint(int);
	int ekef();
	bool equal(Metsoula second);
};

