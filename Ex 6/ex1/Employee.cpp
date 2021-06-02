#include "Employee.h"

//constructors
Employee::Employee(string name, int id, int seniority)
{
	this->name = name;
	this->id = id;
	this->seniority = seniority;
	pay = 0;
}

//this func, return the salary bonus
float Employee::salaryAfterBonus() const
{
	if (seniority <= 5)
		return pay+500;
	return (pay) + pay * 0.25;
}

//operator << of the class
ostream& operator<<(ostream& os, const Employee& emp)
{
	cout << "Employee: " << emp.name << endl;
	cout << "Employee ID: " << emp.id << endl;
	cout << "Years Seniority: " << emp.seniority << endl;

	return os;
}

//operator >> of the class
istream& operator>>(istream& is, Employee& emp)
{
	cout << "Enter employee details:" << endl;
	cin >> emp.name >> emp.id >> emp.seniority;

	return is;
}
