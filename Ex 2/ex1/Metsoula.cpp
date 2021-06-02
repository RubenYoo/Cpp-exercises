#include "Metsoula.h"
#include <iostream>
#include <cmath>
using namespace std;

//Constructor of the Class
//set the default size to 0
//or if the num that the constructor receive is valid
//the construtor set the size to it
Metsoula::Metsoula(int a)
{
	cout << "in construtor" << endl;
	p = NULL;
	size = 0;

	if (a > 0)
	{
		addPoint(a);
		size = a;
	}
	else
		cout << "ERROR" << endl;

}

//Copy constructor of the Class
//receive a Metsoulta object and copy it into the current Metsoula object
Metsoula::Metsoula(const Metsoula& object)
{
	cout << "in copy-constructor" << endl;

	Point* tmp = new Point[object.size];
	size = object.size;

	for (int i = 0; i < size; i++)
	{
		tmp[i].setX(object.p[i].getX());
		tmp[i].setY(object.p[i].getY());
	}

	p = tmp;
}

//Destructor of the Class, that delete the allocated memory
Metsoula::~ Metsoula()
{
	cout << "in destructor" << endl;

	if (size)
		delete[] p;
}

//this func, return the size variable
int Metsoula::getSize() const
{
	return size;
}

//this func,receive a "size", and in function of this size
//add Points objects into the p pointer of the Metsoula object
void Metsoula::addPoint(int a)
{
	char tav;
	int num;
	Point* tmp = new Point[a];
	cout << "enter the point values:" << endl;
	for (int i = 0; i < a; i++)
	{
		cin >> tav >> num;
		tmp[i].setX(num);
		cin >> tav >> num;
		tmp[i].setY(num);
		cin >> tav;
	}

	if(size)
	   delete[] p;

	p = tmp;
}

//this func, return the perimeter of the Metsoula object
int Metsoula::ekef()
{
	float sum = 0;

	for (int i = 0; i < size - 1; i++)
		sum += p[i].distance(p[i + 1]);

	if(size > 0)
	     sum += p[0].distance(p[size-1]);
	return round(sum);                                      //using the func round() from cmath library
}

//this func, receive a Metsoula object , and check if the current
//Metsoula object is equal to the other, if yes the func return true
//if not the func return false
bool Metsoula::equal(Metsoula second)
{
	if (size != second.getSize())
		return false;

	int flag = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (p[i].getX() == second.p[j].getX() && p[i].getY() == second.p[j].getY())
			{
				second.p[j].setX(-1);
				second.p[j].setY(-1);
				flag++;
				break;
			}
	
	if (flag == size)
		return true;
	return false;
}
