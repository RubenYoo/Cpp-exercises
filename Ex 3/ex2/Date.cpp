#include "Date.h"
#include <iostream>

//constructor of the class, that set values to all the variables on the Date Class
Date::Date(int d, int m, int y)
{
	if (d < 1 || d > 30)
	{
		std::cout << "ERROR day\n";
		day = 1;
	}
	else
		day = d;

	if (m < 1 || m > 12)
	{
		std::cout << "ERROR month\n";
		month = 1;
	}
	else
		month = m;

	if (y < 1920 || y > 2099)
	{
		std::cout << "ERROR year\n";
		year = 1920;
	}
	else
		year = y;
}

//copy constructor
Date::Date(const Date& date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

//move constructor
Date::Date(const Date&& date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

//this func, receive 3 num from the user, and change the date with these num, and return the new date
Date Date::setDate(int d,int m,int y)
{
	if (d > 0 && d < 31)
		day = d;
	if (m > 0 && m < 13)
		month = m;
	if (y > 1919 && y < 2100)
		year = y;

	return *this;
}
//this func, and 1 day to a date, and return the new date
Date Date::operator++()
{
	if ((day + 1) > 30)
	{
		if ((month + 1) > 12)
		{
			if ((year + 1) > 2099)
			{
				day = 1;
				month = 1;
				year = 1920;
			}
			else
			{
				year++;
				day = 1;
				month = 1;
			}
		}
		else
		{
			month++;
			day = 1;
		}
	}
	else
		day++;

	return *this;
}

//this func, return the date, and add to it 1 day
Date Date::operator++(int u)
{
	Date temp = *this;

	++(*this);

	return temp;
}

//this func receive a num, and add tbis num to the date, and return the new date
Date Date::operator+=(int num)
{
	if (num > 0)
	{
		if ((day + num) > 30)
		{
			if ((month + (day + num) / 30) > 12)
			{
				if ((year + (day + num) / 360) > 2099)
				{
					day = 1;
					month = 1;
					year = 1920;
				}
				else
				{
					year += (day + num + month * 30) / 360;
					month = ((day + num) % 360) / 30;
					day = ((day + num) % 360) % 30;
				}
			}
			else
			{
				month += (day + num) / 30;
				day = (day + num) % 30;
			}
		}
		else
			day += num;
	}
	else
		std::cout << "ERROR\n";

	return *this;
}

//this func, receive a date a check if this date it's bigger than the current date, if yes the func return false
//if not the func return true
bool Date::operator>(const Date& date) const
{
	if (year > date.year)
		return true;
	else if (year == date.year && month > date.month)
		return true;
	else if (year == date.year && month == date.month && day > date.day)
		return true;

	return false;
}

//this func, receive a date a check if this date it's smaller than the current date, if yes the func return false
//if not the func return true
bool Date::operator<(const Date& date) const
{
	if (year < date.year)
		return true;
	else if (year == date.year && month < date.month)
		return true;
	else if (year == date.year && month == date.month && day < date.day)
		return true;

	return false;
}

//this func, receive a date a check if this date it's equal than the current date, if yes the func return true
//if not the func return false
bool Date::operator==(const Date& date) const
{
	if (year == date.year && month == date.month && day == date.day)
		return true;
	return false;
}

//this func, print the date
void Date::print()
{
	std::cout << day << '/' << month << '/' << year << '\n';
}
