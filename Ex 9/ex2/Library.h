#pragma once
#include <string>
using namespace std;

class Library
{
	//variables of the class
	int code;
	string author;
	string book;
public:
	//constructor
	Library(): code(0), author("\0"),book("\0") {}

	//operators
	bool operator==(Library &lb) const;
	bool operator!=(Library& lb) const;
	bool operator>(Library& lb) const;
	bool operator<(Library& lb) const;
	bool operator<=(Library& lb) const;
	bool operator>=(Library& lb) const;

	friend istream& operator>>(istream& is, Library& lb);
	friend ostream& operator<<(ostream& os,const Library& lb);
};

