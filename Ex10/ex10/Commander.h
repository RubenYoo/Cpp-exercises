#pragma once
#include "Private.h"

class Commander : public Private
{
protected:
	bool combat;
public:
	Commander() : Private::Private(), combat(false) {}
	Commander(int iD, string nameF, string nameL, int op);
	string soldierType();
	bool medal() override;
	void print() override;

	void setCombat();
	bool getCombat() override;

};

