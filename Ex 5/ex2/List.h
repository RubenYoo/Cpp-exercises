#pragma once
#include <iostream>
using namespace std;
//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();

	//operators
	List operator=(List);
	friend ostream& operator<<(ostream& os, const List& l);
	friend istream& operator>>(istream& is, List& l);

	//methods
	void insert(int key);
	void remove(int key);

protected:
	// data field
	Link* head;
};
