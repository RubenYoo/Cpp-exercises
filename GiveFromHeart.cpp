#include "GiveFromHeart.h"
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

//this func, receive a num a set it to an id if the num is valid
void GiveFromHeart::setId(int num)
{
	if (num >= 0)
		id = num;
}

//this func, retun the id
int GiveFromHeart::getId()
{
	return id;
}

//this func, receive a pointer to char array, and set it to the name variable in the class
void GiveFromHeart::setName(char name2[21])
{
	strcpy(name, name2);
}

//this func, is returning a pointer the name array
char* GiveFromHeart::getName()
{
	return name;
}

//this func, receive a num, and set it to the SalaryPerHour variable if the num is valid
void GiveFromHeart::setSalaryPerHour(float num)
{
	if (num >= 0)
		salaryPerHour = num;
}

//this func, return the SalaryPerHour variable
float GiveFromHeart::getSalaryPerHour()
{
	return salaryPerHour;
}

//this func, receive a num, and set it to the setHours variable if the num is valid
void GiveFromHeart::setHours(int num)
{
	if (num >= 0)
		hours = num;
}

//this func, return the getHours variable
int GiveFromHeart::getHours()
{
	return hours;
}

//this func, receive a num, and set it to the inbound variable if the num is valid
void GiveFromHeart::setInbound(float num)
{
	if (num >= 0)
		inbound = num;
}

//this func, return the inbound variable
float GiveFromHeart::getInbound()
{
	return inbound;
}

//this func, is calculating the salary of a worker, and return it
float GiveFromHeart::salary()
{
	float money = 0;

	if (inbound >= 1000)
	{
		money += 0.1 * 1000;
		if (inbound >= 2000)
		{
			money += 0.15 * 1000;
			if (inbound >= 4000)
			{
				money += 2000 * 0.2;
				if (inbound >= 5000)
				{
					money += 1000 * 0.3;
					money += (inbound - 5000) * 0.4;
				}
				else
					money += (inbound - 4000) * 0.3;
			}
			else
				money += (inbound - 2000) * 0.2;
		}
		else
			money += (inbound - 1000) * 0.15;
	}
	else
		money += 0.1 * inbound;

	money += hours * salaryPerHour;
	return money;
}

//constructor of the class
GiveFromHeart::GiveFromHeart()
{
	id = -1;
	salaryPerHour = -1;
	*name = '0';
	hours = -1;
	inbound = -1;
}

//this func, is setting an object to constructor
void GiveFromHeart::clear()
{
	id = -1;
	salaryPerHour = -1;
	*name = '0';
	hours = -1;
	inbound = -1;
}

//this func, check if the data of the class is valid, if yes the func return true
//if not the func return false
bool GiveFromHeart::validityCheck()
{
	if (id == -1 || hours == -1 || inbound == -1 || salaryPerHour == -1)
		return false;
	return true;
}

