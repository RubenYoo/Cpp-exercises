#include "PartTime.h"
#include <iostream>
#include "FullTime.h"
using namespace std;

int main()
{
	//creating 3 full-time employee objects

	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}

	//creating 3 part-time employee objects

	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}

	//printing the 3 full-time employee info, with their bonus
	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
	}

	//printing the 3 part-time employee info, with their bonus
	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
	}
	return 0;
}
/*
Enter employee details:
Enter employee details:
Enter employee details:
Enter employee details:
Enter employee details:
Enter employee details:

Employee: aaa
Employee ID: 1111
Years Seniority: 1
Salary per Month: 2000
After Bonus: 2500

Employee: bbb
Employee ID: 2222
Years Seniority: 2
Salary per Month: 3000
After Bonus: 3500

Employee: ccc
Employee ID: 3333
Years Seniority: 6
Salary per Month: 4000
After Bonus: 5000

Employee: ddd
Employee ID: 4444
Years Seniority: 3
Hours: 160
Salary per Month: 5600
After Bonus: 6100

Employee: eee
Employee ID: 5555
Years Seniority: 4
Hours: 200
Salary per Month: 9000
After Bonus: 9500

Employee: fff
Employee ID: 6666
Years Seniority: 7
Hours: 240
Salary per Month: 12000
After Bonus: 15000
*/
