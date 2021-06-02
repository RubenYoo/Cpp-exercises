#pragma once
#include "Employee.h"

class PartTime : public Employee
{
	//variables
	int hourOfWork;
	float salaryPerHour;
public:
	//constructors
	PartTime(string name, int id, int seniority, int hour, int salary) : Employee(name, id, seniority), hourOfWork(hour), salaryPerHour(salary)
	{}
	PartTime() : Employee("\0", 0, 0), hourOfWork(0), salaryPerHour(0)
	{}

	//method
	void salary();

	//operators
	friend ostream& operator<<(ostream& os, const PartTime& partT);
	friend istream& operator>>(istream& is, PartTime& partT);
};

