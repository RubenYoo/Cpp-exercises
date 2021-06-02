#pragma once
#include "Soldier.h"

class Private : public Soldier
{
protected:
	int *array;
public:
	Private(): Soldier::Soldier(), array(nullptr) {}
	Private(int iD, string nameF, string nameL, int op);
	~Private();
	string soldierType();
	bool medal() override;
	void print() override;

	void setGrades();


};

