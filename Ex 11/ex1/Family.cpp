#include "Family.h"
#include <cstring>
#include <iostream>

//this func, receive a num and set it as the Family number
void Family::setFamilyNum(int num)
{
	familyNum = num;
}

//contructor
Family::Family(int famNum, char str[20], int memNum, int tel)
{
	setFamilyNum(famNum);
	setName(str);
	setMemberNum(memNum);
	setTelephone(tel);
	for (int i = 0; i < 6; i++)
		activities[i] = false;	
}

//this func, receive an array of char and set it as the Family name
void Family::setName(char str[20])
{
	strcpy_s(name, str);
}

//this func, receive a num and set it as the Member number
void Family::setMemberNum(int num)
{
	if (num > -1)
		memberNum = num;
	else
		memberNum = 0;
}

//this func, receive a num and set it as the Phone number
void Family::setTelephone(int tel)
{
	if (tel > -1)
		telephone = tel;
	else
		telephone = 0;
}

//this func, receive a num of an activity and a true or false boolean, and set the activity as the boolean
void Family::setActivities(bool bo, int i)
{
	activities[i] = bo;
}

//this fun, return the Family number
int Family::getFamilyNum() const
{
	return familyNum;
}

//this fun, return the Family name
char* Family::getName()
{
	return name;
}

//this fun, return the Member number
int Family::getMemberNum() const
{
	return memberNum;
}

//this fun, return the Phone number
int Family::getTelephone() const
{
	return telephone;
}

//this func, receive a num of an activity, and return if the activity is true or false
bool Family::getActivities(int i) const
{
	return activities[i];
}
