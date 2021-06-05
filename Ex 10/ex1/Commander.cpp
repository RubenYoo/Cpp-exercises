#include "Commander.h"
#include <iostream>
using namespace std;

//construcor
Commander::Commander(int iD, string nameF, string nameL, int op) : Private(iD,nameF,nameL,op)
{
	setCombat();
}

//this func, return the type of the soldier
string Commander::soldierType() const
{
    return "commander";
}

//this func, return if the soldier is eligible for a medal
bool Commander::medal() const
{
	if (numOp > 6 && combat)
	{
		for (int i = 0; i < numOp; i++)
		{
			if (array[i] < 90)
				return false;
		}
		return true;
	}

	return false;
}

//this func, print all the data of the soldier
void Commander::print() const
{
	Private::print();
	cout << "combat: ";

	if (combat)
		cout << "yes\n";
	else
		cout << "no\n";
}

//this func, set if the soldier is a combat soldier or not
void Commander::setCombat()
{
	int x;
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> x;
	if (x == 1)
		combat = true;
	else if (x == 0)
		combat = false;
	else
		throw "Please enter 1 or 0\n";
}

//this func, return if the soldier is a combat soldier or not
bool Commander::getCombat() const
{
	if (combat)
		return true;
	return false;
}
