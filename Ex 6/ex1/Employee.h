#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
	//variables of the Employee Class
	string name;
	int id;
	int seniority;
	float pay;
public:
	//constructor
	Employee(string,int,int);

	//method
	float salaryAfterBonus() const;

	//operators
	friend ostream& operator<<(ostream& os, const Employee& emp);
	friend istream& operator>>(istream& is, Employee& emp);
};

