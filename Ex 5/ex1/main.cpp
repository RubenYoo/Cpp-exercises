#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	//declaring the variables
	List lst;
	int choice, val;

	//read the nums to enter in the list
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;

	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";		//add a value in th list
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";		//remove a value in the list
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (const char *msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;							//print the list
		cout << "choose 0-2\n";
		cin >> choice;
	}

	return 0;
}
/*
* enter the list values
3 2 1 1
choose 0 - 2
2
enter a value to remove
2
3 1
choose 0 - 2
1
enter a value to insert
4
4 3 1
choose 0 - 2
1
enter a value to insert
2
4 3 2 1
choose 0 - 2
0

*/
