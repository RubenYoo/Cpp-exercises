#include "Rational.h"
#include <iostream>

//This func, is reducing a Rational num, and return it
Rational Rational::reduction()
{

	for (int i = x; i > 0; i--)
	{
		if((x % i == 0) && (y % i == 0))
		{
			x /= i;
			y /= i;
		}
	}
	if (x < 0 && y < 0)
	{
		x = x * -1;
		y = y * -1;
	}
	return Rational();
}

//this func, receive a num and set it to be the denominator if the num is valid, if not set the
//denominator to 1
void Rational::setDenominator(int denominator)
{
	if (denominator != 0)
		y = denominator;
	else
		y = 1;
}

//this func return the denominator
int Rational::getDenominator()
{
	return y;
}

//this func, receive and num and set it to be the numerator
void Rational::setNumerator(int numerator)
{
	x = numerator;
}

//this fuc, return the numerator
int Rational::getNumerator()
{
	return x;
}

//this func, receive a Rational object and print it
void Rational::print()
{
	std::cout << x << '/' << y << ' ';
}

//this func, receive a Rational object, and check if it equal to another Rational object
//if it is, the func return true, if not the func return false
bool Rational::equal(Rational num)
{
	Rational a, b;
	a.x = x, a.y = y;
	b.x = num.x, b.y = num.y;
	a.reduction();
	b.reduction();

	if (a.x == b.x && a.y == b.y)
		return true;
	else
		return false;

}

//this func receive a rational object, and add to another Rational object, and return it
Rational Rational::add(Rational num)
{
	Rational addition;
	
	addition.x = (x * num.y) + (num.x * y);
	addition.y = num.y * y;
	addition.reduction();

	return addition;
}
