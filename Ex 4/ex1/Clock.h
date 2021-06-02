#pragma once

#include <iostream>
using namespace std;

class Clock
{
	//private variables of the class
	int hour = 0;
	int minute = 0;
	int second = 0;

public:
	//constructors
	Clock();
	Clock(int h = 0,int m = 0,int s = 0);
	Clock(const Clock &time);

	//gets methods
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	//sets methods
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	//operators
	Clock operator+=(int s);
	friend ostream& operator<<(ostream& os, const Clock& t);
	friend istream& operator>>(istream& is, Clock& t);
};

