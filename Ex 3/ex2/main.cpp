#include "Date.h"
#include <iostream>
using namespace std;


int main() {

	//delcaring the variables
	int day, month, year, num;
	char tav;

	cout << "Enter a date\n";
	cin >> day >> tav >> month >> tav >> year; //reading the date

	Date date(day, month, year);               //creating the date
	date.print();                              //print the date

	cout << "Enter an action code: \n";
	cin >> num;

	while (num != -1)
	{
		Date date2;
		switch (num)
		{
			//changing the date
		case 1: cout << "Enter a date\n"; cin >> day >> tav >> month >> tav >> year; (date.setDate(day,month,year)).print(); break;
			//add 1 to a date
		case 2: (++date).print(); break;
			//add 1 to a date
		case 3: (date++).print(); break;
			//add # days to a date
		case 4: cout << "Enter # days\n"; cin >> day; (date += day).print(); break;
			//check which date are bigger
		case 5: cout << "Enter a date\n"; cin >> day >> tav >> month >> tav >> year; date2.setDate(day, month, year); date > date2 ? cout << ">: true\n" : cout << ">: false\n"; break;
			//check which date are smaller
		case 6: cout << "Enter a date\n"; cin >> day >> tav >> month >> tav >> year; date2.setDate(day, month, year); date < date2 ? cout << "<: true\n" : cout << "<: false\n"; break;
			//check if the the two date are equal
		case 7: cout << "Enter a date\n"; cin >> day >> tav >> month >> tav >> year; date2.setDate(day, month, year); date == date2 ? cout << "==: true\n" : cout << "==: false\n"; break;
		default: cout << "ERROR\n"; break;
		}
		cout << "Enter an action code: \n";
		cin.ignore();
		cin >> num;
	}

	return 0;
}
