#include "FullTime.h"

//operator << of the class
ostream& operator<<(ostream& os, const FullTime& fullT)
{
	cout << endl;
	Employee tmp = fullT;
	cout << tmp;
	cout << "Salary per Month : " << fullT.pay << endl;

	return os;
}

//operator >> of the class
istream& operator>>(istream& is, FullTime& fullT)
{
	Employee* tmp = &fullT;
	cin >> *tmp;
	cin >> fullT.yearPay;

	if (fullT.yearPay < 0 || fullT.id < 0 || fullT.seniority < 0 || fullT.name == "\0")
		throw "ERROR\n";

	fullT.salary();

	return is;
}

//this func, calculate the pay of the employee
void FullTime::salary()
{
	pay = yearPay / 12;
}
