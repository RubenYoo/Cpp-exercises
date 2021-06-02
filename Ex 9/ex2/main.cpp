#include <iostream>
using namespace std;
#include "Library.h"
#include "SearchTree.h"

int main()
{
	//declaring the variables
	char ch;
	SearchTree<Library> T1;
	Library lb;

	cout << "enter a-e:\n";
	cin >> ch;

	while (ch != 'e')
	{
		switch (ch)
		{
		case 'a':	//add a book the the library
		{
			cout << "enter a book\n";
			cin >> lb;
			T1.add(lb);

			break;
		}
		case 'b':	//remove a book from the library
		{
			cout << "enter a book\n";
			cin >> lb;
			T1.remove(lb);
			break;
		}
		case 'c':	//search a book from the library
		{
			cout << "enter a book\n";
			cin >> lb;
			if (T1.search(lb))
				cout << "exist\n";
			else
				cout << "not exist\n";
			break;
		}
		case'd':	//print all the library
		{
			T1.inOrder();
			break;
		}

		default: cout << "ERROR\n";
			break;
		}
		cout << "enter a-e:\n";
		cin >> ch;
	}

	return 0;
}
/*
enter a-e:
a
enter a book:
2 b b
enter a-e:
a
enter a book:
5 e e
enter a-e:
a
enter a book:
1 a a
enter a-e:
a
enter a book:
4 d d
enter a-e:
a
enter a book:
7 g g
enter a-e:
a
enter a book:
3 c c
enter a-e:
b
enter a book:
5 e e
enter a-e:
d
1 a a
2 b b
3 c c
4 d d
7 g g
enter a-e:
e
*/