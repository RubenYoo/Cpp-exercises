#pragma once
#include "Private.h"

class Commander : public Private
{
protected:
	//private variable
	bool combat;
public:
	//constructors
	Commander() : Private::Private(), combat(false) {}
	Commander(int iD, string nameF, string nameL, int op);

	//methods
	string soldierType() const override;
	bool medal() const override;
	void print() const override;
	void setCombat();
	bool getCombat() const override;

};

