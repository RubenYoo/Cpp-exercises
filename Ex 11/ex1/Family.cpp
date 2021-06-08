#include "Family.h"
#include <cstring>
#include <iostream>

void Family::setFamilyNum(int num)
{
	familyNum = num;
}

Family::Family(int famNum, char str[20], int memNum, int tel)
{
	try
	{
		setFamilyNum(famNum);
		setName(str);
		setMemberNum(memNum);
		setTelephone(tel);
		for (int i = 0; i < 6; i++)
		{
			activities[i] = true;
		}
	}
	catch (const char* stri)
	{
		std::cout << stri;
	}
	
}

void Family::setName(char str[20])
{
	strcpy_s(name, str);
}

void Family::setMemberNum(int num)
{
	memberNum = num;
}

void Family::setTelephone(int tel)
{
	telephone = tel;
}

void Family::setActivities(bool bo, int i)
{
	activities[i] = bo;
}

int Family::getFamilyNum() const
{
	return familyNum;
}

char* Family::getName()
{
	return name;
}

int Family::getMemberNum() const
{
	return memberNum;
}

int Family::getTelephone() const
{
	return telephone;
}

bool Family::getActivities(int i) const
{
	return activities[i];
}
