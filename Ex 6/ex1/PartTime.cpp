#include "PartTime.h"

//operator << of the class
ostream& operator<<(ostream& os, const PartTime& partT)
{
	cout << endl;
	Employee tmp = partT;
	cout << tmp;
	cout << "Hours: " << partT.hourOfWork << endl;
	cout << "Salary per Month: " << partT.pay << endl;

	return os;
}

//opeator >> of the class
istream& operator>>(istream& is, PartTime& partT)
{
	Employee* tmp = &partT;
	cin >> *tmp;
	cin >> partT.hourOfWork >> partT.salaryPerHour;

	if (partT.hourOfWork < 0 || partT.salaryPerHour < 0 || partT.id < 0 || partT.seniority < 0 || partT.name == "\0")
		throw "ERROR\n";

	partT.salary();

	return is;
}

//this func, calculate the pay of the employee
void PartTime::salary()
{
	pay = hourOfWork * salaryPerHour;
}
