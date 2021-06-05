#pragma once
#include "Soldier.h"

class Officer : public Soldier
{
protected:
	//private variable
	int sociometric;
public:
	//constructors
	Officer() : Soldier::Soldier(), sociometric(0) {}
	Officer(int iD, string nameF, string nameL, int op);
	
	//methods
	string soldierType() const override;
	bool medal() const override;
	void print() const override;
	void setSocio();
	int getSocio() const override;

};

