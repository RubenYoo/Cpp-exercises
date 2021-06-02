#include <iostream>
using namespace std;
#include "SearchTree.h"
enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
	//creating the binary tree object
	SearchTree<int> T1;
	
	cout << "enter 10 numbers:\n";
	int x, y, z;

	//add 10 values into the tree
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}

	//print the tree in inorder
	cout << "inorder: ";
	T1.inOrder();

	cout << "\nenter 0-8:\n";
	cin >> x;
	while (x != END)
	{
		switch (x)
		{
			//add a value to the tree
		case ADD: cout << "enter a number: ";
			cin >> y;
			T1.add(y);
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
			break;
			//search if a num exist in the tree
		case SEARCH: cout << "enter a number: ";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "no exist" << endl;
			break;
			//remove a val from the true
		case REMOVE:cout << "enter a number: ";
			cin >> y;
			try
			{
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.inOrder();
				cout << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
			//print the tree in a breadthscan
		case BREADTHSCAN: cout << "breadth scan: ";
			T1.breadthScan();
			cout << endl;
			break;
			//print the height of the tree
		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;
			//print the successor of a value
		case SUCCESSOR:cout << "enter a number: ";
			cin >> y;
			try
			{
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;

			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
			//delete the duplicates values
		case DELETEDUP: cout << "after delete duplicate: ";
			T1.deleteDuplicates();
			T1.inOrder();
			cout << endl;
			break;
			//reflect all the tree
		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}
		cout << "enter 0-8:\n";
		cin >> x;
	}
	return 0;
}
/*
enter 10 numbers:
1 2 3 4 5 6 7 8 9 10
inorder: 1 2 3 4 5 6 7 8 9 10
enter 0-8:
1
enter a number: 11
after adding 11: 1 2 3 4 5 6 7 8 9 10 11
enter 0-8:
2
enter a number: 3
exist
enter 0-8:
1
enter a number: 3
after adding 3: 1 2 3 3 4 5 6 7 8 9 10 11
enter 0-8:
3
enter a number: 8
after removing 8: 1 2 3 3 4 5 6 7 9 10 11
enter 0-8:
5
height of tree: 9
enter 0-8:
7
after delete duplicate: 1 2 3 4 5 6 7 9 10 11
enter 0-8:
8
reflected tree: 11 10 9 7 6 5 4 3 2 1
enter 0-8:
4
breadth scan: 1 2 4 3 5 6 7 9 10 11
enter 0-8:
0
*/
