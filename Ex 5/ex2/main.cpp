#include <iostream>
#include "List.h"
using namespace std;

//prototypes of the funcs
List merge(List lst1, List lst2);
void makeSet(List& lst);
void reverse(List& lst);

int main()
{
	//declaring the variables
	List lst1, lst2, mergedList;

	//read the nums into the two lists
	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	//merge sort the two list, and print it
	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	//remove duplicate numbers from the merged list and print it
	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	//reverse the merged list and print it
	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}

//this func, receive two list, and merge sort them into a third list and return this new list
List merge(List lst1, List lst2)
{
	List mergedList;

	while (!lst1.isEmpty())
	{
		mergedList.insert(lst1.firstElement());
		lst1.removeFirst();
	}

	while (!lst2.isEmpty())
	{
		mergedList.insert(lst2.firstElement());
		lst2.removeFirst();
	}
	
	return mergedList;
}

//this func, receive a list, and remove duplicate nums
void makeSet(List &lst)
{
	List copyLst = lst;
	int tmp;

	while (!copyLst.isEmpty())
	{
		tmp = copyLst.firstElement();
		copyLst.removeFirst();

		if (copyLst.search(tmp))
			lst.remove(tmp);
	}
}

//this func receive a list, and reverse it
void reverse(List& lst)
{
	List copyLst = lst;
	lst.clear();
	
	while (!copyLst.isEmpty())
	{
		lst.add(copyLst.firstElement());
		copyLst.removeFirst();
	}

}
/*
enter sorted values for the first list :
6 5 4 3 2 1 9
enter sorted values for the second list :
7 5 4 3 9
the new merged list : 7 6 5 5 4 4 3 3 2 1
the new merged set : 7 6 5 4 3 2 1
the new merged reverse : 1 2 3 4 5 6 7
Press any key to continue . . .
*/
