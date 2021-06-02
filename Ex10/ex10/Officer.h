#pragma once
#include "Soldier.h"

class Officer : public Soldier
{
protected:
	int sociometric;
public:
	Officer() : Soldier::Soldier(), sociometric(0) {}
	Officer(int iD, string nameF, string nameL, int op);
	string soldierType();
	bool medal() override;
	void print() override;

	void setSocio();
	int getSocio() override;

};

