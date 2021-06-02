#include "List.h"
#include <iostream>
using namespace std;

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr)
{
	// no further initialization
}

//constructor
List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

//destructor
List::~List()
{
	clear();
}

//func that clear the list
void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

//this func, receive a list and copy the content of the current list to the new list and return it
List List::operator=(List l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}

//this func, receive a key, and add it to the list
void List::insert(int key)
{
	Link* p = head;

	while (p != nullptr && key < head->value)
	{
		if (key < p->value && p->next != nullptr && key < p->next->value)
		{
			p = p->next;
		}
		else
		{
			p->next = new Link(key, p->next);
			break;
		}
	}

	if (head == nullptr || key >= head->value)
		add(key);
}

//this finc, receive a key and remove it from the list
void List::remove(int key)
{
	if (!search(key))
		throw "value not found";
	else
	{
		if (head->value == key)
			removeFirst();
		else
		{
			Link* p = head->next, * p2 = head;
			while (p != nullptr)
			{
				if (p->value == key)
				{
					p2->next = p->next;
					delete p;
					break;
				}
				else
				{
					p2 = p;
					p = p->next;
				}
			}
		}

	}
}

//this func check if the list is empty or not
bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

//this func, add a key at the first place of the list
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

//this func, return the first element of the list
int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

//this func, receive a val and check if the val is in the list
bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

//this func, remove the first key of the list
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

//operatotr<< for the class
ostream& operator<<(ostream& os, const List& l)
{
	List::Link* p;
	p = l.head;

	while (p != nullptr)
	{
		cout << p->value << ' ';
		p = p->next;
	}

	return os;
}

//operator >> of the class
istream& operator>>(istream& is, List& l)
{
	int num;

	if (l.head == nullptr)
	{
		cin >> num;
		l.add(num);
	}

	cin >> num;
	List::Link* p = l.head;

	while (p->value > num)
	{
		p->next = new List::Link(num, nullptr);
		p = p->next;
		cin >> num;
	}

	return is;
}
