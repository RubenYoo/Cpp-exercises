#pragma once
#include <string>
using namespace std;

class Soldier
{
protected:
	int id;
	string firstName;
	string lastName;
	int numOp;
public:
	Soldier(): id(0), firstName("\0"), lastName("\0"), numOp(0) {}
	Soldier(int iD, string nameF, string nameL, int op);

	virtual ~Soldier() {}
	virtual string soldierType() = 0;

	virtual bool medal() = 0;
	virtual void print();
	virtual int getSocio();

	virtual int getNumOp();
	virtual string getFname();
	virtual string getName();
	virtual bool getCombat();

};

