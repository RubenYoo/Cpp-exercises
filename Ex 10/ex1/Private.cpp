#include "Private.h"
#include <iostream>
using namespace std;

//constructor
Private::Private(int iD, string nameF, string nameL, int op) : Soldier::Soldier(iD,nameF,nameL,op)
{
	if (numOp)
	{
		int* arr = new int[numOp];
		array = arr;
		setGrades();
	}
}

//desturctor
Private::~Private()
{
	if (numOp)
		delete[] array;
}

//this func, return the type of the soldier
string Private::soldierType() const
{
	return "private";
}

//this func, return if the soldier is eligible for a medal
bool Private::medal() const
{
	int sum = 0;
	if (numOp > 9)
	{
		for (int i = 0; i < numOp; i++)
		{
			sum += array[i];
		}
	}

	sum = sum / numOp;

	if(sum >= 95)
		return true;
	return false;
}

//this func, print all the data of the soldier
void Private::print() const
{
	cout << soldierType() << endl;
	Soldier::print();
	cout << "grades: ";
	for (int i = 0; i < numOp; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

//this func, set the grades of the operations
void Private::setGrades()
{
	int num;
	cout << "enter " << numOp << " grades\n";
	for (int i = 0; i < numOp; i++)
	{
		cin >> num;
		if (num >= 0 && num <= 100)
			array[i] = num;
		else
		{
			cout << "Invalid grade\n";
			i--;
		}
	}
}
