#include "Officer.h"
#include <iostream>
using namespace std;

Officer::Officer(int iD, string nameF, string nameL, int op) : Soldier::Soldier(iD, nameF, nameL, op)
{
	setSocio();
}

string Officer::soldierType()
{
	return "officer";
}

bool Officer::medal()
{
	if (numOp > 2 && sociometric > 92)
		return true;
	return false;
}

void Officer::print()
{
	cout << soldierType() << endl;
	Soldier::print();
	cout << "sociometric score: " << sociometric << endl;
}

void Officer::setSocio()
{
	int x;
	cout << "enter number of sociometric score\n";
	cin >> x;

	if (x < 0 || x > 100)
		throw "Invalid sociometric score\n";
	sociometric = x;
}

int Officer::getSocio()
{
	return sociometric;
}
