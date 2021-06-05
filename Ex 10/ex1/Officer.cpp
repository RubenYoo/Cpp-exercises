#include "Officer.h"
#include <iostream>
using namespace std;

//contructor
Officer::Officer(int iD, string nameF, string nameL, int op) : Soldier::Soldier(iD, nameF, nameL, op)
{
	setSocio();
}

//this func, return the type of the soldier
string Officer::soldierType() const
{
	return "officer";
}

//this func, return if the soldier is eligible for a medal
bool Officer::medal() const
{
	if (numOp > 2 && sociometric > 92)
		return true;
	return false;
}

//this func, print all the data of the soldier
void Officer::print() const
{
	cout << soldierType() << endl;
	Soldier::print();
	cout << "sociometric score: " << sociometric << endl;
}

//this func, set the grade of the sociometric
void Officer::setSocio()
{
	int x;
	cout << "enter number of sociometric score\n";
	cin >> x;

	if (x < 0 || x > 100)
		throw "Invalid sociometric score\n";
	sociometric = x;
}

//this func, return the sociometric grade
int Officer::getSocio() const
{
	return sociometric;
}
