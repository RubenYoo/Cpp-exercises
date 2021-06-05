#pragma once
#include "Soldier.h"

class Private : public Soldier
{
protected:
	//private variable
	int *array;
public:
	//constructors
	Private(): Soldier::Soldier(), array(nullptr) {}
	Private(int iD, string nameF, string nameL, int op);

	//destructor
	~Private();

	//methods
	string soldierType() const override;
	bool medal() const override;
	void print() const override;
	void setGrades();
};

