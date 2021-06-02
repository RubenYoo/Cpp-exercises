#pragma once
class Date
{
	//private variables of Date class
	int day;
	int month;
	int year;
public:

	Date(int d=1,int m=1,int y=1920); //constructor
	Date(const Date&);                //copy constructor
	Date(const Date&&);               //move constructor

	Date setDate(int, int,int);       //change date method  
	void print();                     //print date method

	//all the operator methods
	Date operator++();
	Date operator++(int);
	Date operator+=(int);
	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
};

