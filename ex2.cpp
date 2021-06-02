#include <iostream>
#include <cstring>
#include "GiveFromHeart.h"

using namespace std;

int main() {

	//declaring all the variables
	GiveFromHeart tmp, little, big;
	int id, hours;
	char name[21];
	float salaryPerHour, inbound;


	cout << "enter details, to end enter 0:\n";
	cin >> id;
	while (id)                                                                 //reading worker informations
	{
		cin.ignore();
		cin.getline(name,21,' ');
		cin >> salaryPerHour;
		cin >> hours;
		cin >> inbound;

		tmp.setId(id);                                                         //creating an object with these informations
		tmp.setName(name);
		tmp.setSalaryPerHour(salaryPerHour);
		tmp.setHours(hours);
		tmp.setInbound(inbound);

		if (little.getId() == -1 && big.getId() == -1 && tmp.validityCheck())  //checking if it is the first worker or not
		{
			little = tmp;
			big = tmp;
		}
		else if (tmp.validityCheck())                                          //do a swap if the new worker have a bigger salary
		{                                                                      //or a less inbound
			if (tmp.getInbound() < little.getInbound())
				little = tmp;
			if (tmp.salary() > big.salary())
				big = tmp;
		}
		else                                                                   //printing ERROR if the informations is not valid
			cout << "ERROR" << endl;

		tmp.clear();
		cin >> id;
	}

	if (little.getId() != -1)                                                  //checking if at least there are 1 valid worker
	{
		//printing the worker is the minimum sum, and the worker with the highest salary
		cout << "minimum sum: " << little.getInbound() << ' ' << little.getName() << ' ' << little.getId() << endl;
		cout << "highest salary: " << big.salary() << ' ' << big.getName() << ' ' << big.getId();
	}
	else                                                                       //print an error if there are not at least 1 valid worker
		cout << "No (valid) informations have been entered";

	return 0;
}
/*
enter details, to end enter 0:
111111111  doron  35  120  6000
222222222  tal  50  55  1400
444444444  levi  45  -4  100
ERROR
333333333  naomi  30  120  800
0
minimum sum: 800 naomi 333333333
highest  salary : 5550 doron 111111111
*/