#include "Private.h"
#include <iostream>
using namespace std;

Private::Private(int iD, string nameF, string nameL, int op) : Soldier::Soldier(iD,nameF,nameL,op)
{
	if (numOp)
	{
		int* arr = new int[numOp];
		array = arr;
		setGrades();
	}
}

Private::~Private()
{
	if (numOp)
		delete[] array;
}

string Private::soldierType()
{
	return "private";
}

bool Private::medal()
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

void Private::print()
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
