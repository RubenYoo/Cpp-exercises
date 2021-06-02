#include "Clock.h"
#include <iostream>
using namespace std;

//constructor without parameters
Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

//constructor with parameters
Clock::Clock(int h, int m, int s)
{

	if (s > 60)
		throw "Invalid time - more than 60 seconds.\n";
	if (m > 60)
		throw "Invalid time - more than 60 minutes.\n";
	if (h > 24)
		throw "Invalid time - more than 24 hours.\n";
	if (s < 0)
		throw "Invalid time - negative number of seconds.\n";
	if (m < 0)
		throw "Invalid time - negative number of minutes.\n";
	if (h < 0)
		throw "Invalid time - negative number of hours.\n";

	hour = h, minute = m, second = s;
}

//copy constructor
Clock::Clock(const Clock& time)
{
	hour = time.hour;
	minute = time.minute;
	second = time.second;
}

//this func, return the hour
int Clock::getHour() const
{
	return hour;
}

//this func, return the minute
int Clock::getMinute() const
{
	return minute;
}

//this func, return the second
int Clock::getSecond() const
{
	return second;
}

//this func, receive an num set it as the hour
void Clock::setHour(int h)
{
	if (h > 24)
		throw "Invalid time - more than 24 hours.\n";
	if (h < 0)
		throw "Invalid time - negative number of hours.\n";
	hour = h;
}

//this func, receive a num and set it as the minute
void Clock::setMinute(int m)
{
	if (m > 60)
		throw "Invalid time - more than 60 minutes.\n";
	if (m < 0)
		throw "Invalid time - negative number of minutes.\n";
	minute = m;
}

//this func, receive a num and set it as the second
void Clock::setSecond(int s)
{
	if (s > 60)
		throw "Invalid time - more than 60 seconds.\n";
	if (s < 0)
		throw "Invalid time - negative number of seconds.\n";
	second = s;
}

//operator =+, receive a num and add it to the clock, and return the clock object
Clock Clock::operator+=(int s)
{
	second += s;
	minute += second / 60;
	second %= 60;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;

	return *this;
}

//operator <<, receive a ostream and Clock object, and return a ostream object
ostream& operator<<(ostream& os,const Clock& t)
{
	if (t.hour > 9)
		cout << t.hour << ":";
	else
		cout << '0' << t.hour << ":";

	if(t.minute > 9)
		cout << t.minute << ":";
	else
		cout << '0' << t.minute << ":";

	if (t.second > 9)
		cout << t.second;
	else
		cout << '0' << t.second;

	return os;
}

//operator >>, receive a istream and Clock object, and return a istream object
istream& operator>>(istream& is, Clock& t)
{
	int h, m, s;
	char tav;
	cin >> h >> tav >> m >> tav >> s;

	t.setHour(h);
	t.setMinute(m);
	t.setSecond(s);

	return is;
}
