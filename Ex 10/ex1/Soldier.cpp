#include "Soldier.h"
#include <iostream>
using namespace std;

Soldier::Soldier(int iD, string nameF, string nameL, int op)
{
	if (iD < 0)
		throw "Invalid ID\n";
	if (nameF == "\0" || nameL == "\0")
		throw "Invalid Name\n";
	if (op < 0)
		throw "Invalid operation number\n";

	id = iD;
	firstName = nameF;
	lastName = nameL;
	numOp = op;
}

void Soldier::print()
{
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << numOp << endl;
}

int Soldier::getSocio()
{
	throw "ERROR: this function is just for officer soldier";
}

int Soldier::getNumOp()
{
	return numOp;
}

string Soldier::getFname()
{
	return firstName;
}

string Soldier::getName()
{
	return lastName;
}

bool Soldier::getCombat()
{
	return true;
}
