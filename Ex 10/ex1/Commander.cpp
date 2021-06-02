#include "Commander.h"
#include <iostream>
using namespace std;

Commander::Commander(int iD, string nameF, string nameL, int op) : Private(iD,nameF,nameL,op)
{
	setCombat();
}

string Commander::soldierType()
{
    return "commander";
}

bool Commander::medal()
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

void Commander::print()
{
	//cout << soldierType() << endl;
	Private::print();
	cout << "combat: ";

	if (combat)
		cout << "yes\n";
	else
		cout << "no\n";
}

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

bool Commander::getCombat()
{
	if (combat)
		return true;
	return false;
}
