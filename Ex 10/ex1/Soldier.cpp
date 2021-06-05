#include "Soldier.h"
#include <iostream>
using namespace std;

//constructor
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

//this func, print all the data of the soldier
void Soldier::print() const
{
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << numOp << endl;
}

//this func, return the socio grade
int Soldier::getSocio() const
{
	throw "ERROR: this function is just for officer soldier";
}

//this func, return the num of operations
int Soldier::getNumOp() const
{
	return numOp;
}

//this func, return the first name
string Soldier::getFname() const
{
	return firstName;
}

//this func, return the last name
string Soldier::getName() const
{
	return lastName;
}

//this func, return if the soldier is a combat soldier or not
bool Soldier::getCombat() const
{
	return true;
}
