#pragma once
#include <string>
using namespace std;

class Soldier
{
protected:
	//private variables
	int id;
	string firstName;
	string lastName;
	int numOp;
public:
	//constructors
	Soldier(): id(0), firstName("\0"), lastName("\0"), numOp(0) {}
	Soldier(int iD, string nameF, string nameL, int op);

	//virtual methods
	virtual ~Soldier() {}
	virtual string soldierType() const = 0;

	virtual bool medal() const = 0;
	virtual void print() const;
	virtual int getSocio() const;

	virtual int getNumOp() const;
	virtual string getFname() const;
	virtual string getName() const;
	virtual bool getCombat() const;

};

