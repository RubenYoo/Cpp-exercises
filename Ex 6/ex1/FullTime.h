#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

class FullTime : public Employee
{
	//variable
	float yearPay;

public:
	//constructors
	FullTime(string name,int id,int seniority,int pay): Employee(name,id,seniority), yearPay(pay)
	{}
	FullTime(): Employee("\0", 0, 0), yearPay(0)
	{}

	//method
	void salary();

	//operators
	friend ostream& operator<<(ostream& os, const FullTime& fullT);
	friend istream& operator>>(istream& is, FullTime& fullT);

};

