#include "Rational.h"
#include <iostream>
#include <cmath>

//constructor of the Class, set to the numerator and denominator values
Rational::Rational(int x = 0, int y = 1)
{
	numerator = x;

	if (y != 0)
		denominator = y;
	else
	{
		std::cout << "ERROR\n";
		denominator = 1;
	}
}


 //This func, is reducing a Rational num, and return it
Rational Rational::reduction()
{

	for (int i = std::abs(numerator) * std::abs(denominator); i > 1; i--)
	{
		if ((numerator % i == 0) && (denominator % i == 0))
		{
			numerator /= i;
			denominator /= i;
		}
	}
	if (numerator == 0)
	{
		denominator = 1;
	}
	if (numerator < 0 && denominator < 0)
	{
		numerator = numerator * -1;
		denominator = denominator * -1;
	}
	return *this;
}

//this func, receive a num and set it to be the denominator if the num is valid, if not set the
//denominator to 1
void Rational::setDenominator(int denominator)
{
	if (denominator != 0)
		this->denominator = denominator;
	else
		this->denominator = 1;
}

//this func return the denominator
int Rational::getDenominator() const
{
	return denominator;
}

//this func, receive and num and set it to be the numerator
void Rational::setNumerator(int numerator)
{
	this->numerator = numerator;
}

//this fuc, return the numerator
int Rational::getNumerator() const
{
	return numerator;
}

//this func, receive a Rational object and print it
void Rational::print()
{
	this->reduction();

	if (numerator == 0)
		std::cout << "0";
	else if (denominator == 1)
		std::cout << numerator;
	else
		std::cout << numerator << '/' << denominator;
}

//this func, receive a Rational object, and check if it equal to another Rational object
//if it is, the func return true, if not the func return false
bool Rational::operator==(const Rational& num) const
{
	if (numerator * num.denominator == num.numerator * denominator)
		return true;
	return false;
}

//this func receive a rational object, and add to another Rational object, and return it
Rational Rational::operator+(const Rational& num)
{
	Rational newNum;
	if (numerator == 0)
	{
		newNum.numerator = num.numerator;
		newNum.denominator = num.denominator;
	}
	else if (num.numerator == 0)
	{
		newNum.numerator = numerator;
		newNum.denominator = denominator;
	}
	else
	{
		newNum.numerator = (numerator * num.denominator) + (num.numerator * denominator);
		newNum.denominator = num.denominator * denominator;
	}

	return newNum;
}

//this func receive a rational object, and substract it to another Rational object, and return it
Rational Rational::operator-(const Rational& num)
{
	Rational newNum;
	if (numerator == 0)
	{
		newNum.numerator = -num.numerator;
		newNum.denominator = num.denominator;
	}
	else if (num.numerator == 0)
	{
		newNum.numerator = numerator;
		newNum.denominator = denominator;
	}
	else
	{
		newNum.numerator = (numerator * num.denominator) - (num.numerator * denominator);
		newNum.denominator = num.denominator * denominator;
	}

	return newNum;
}

//this func receive a rational object, and divide it to another Rational object, and return it
Rational Rational::operator/(const Rational& num)
{
	Rational newNum;

	newNum.numerator = numerator * num.denominator;
	newNum.denominator = denominator * num.numerator;

	return newNum;
}

//this func receive a rational object, and multiply it to another Rational object, and return it
Rational Rational::operator*(const Rational& num)
{
	Rational newNum;

	newNum.numerator = numerator * num.numerator;
	newNum.denominator = denominator * num.denominator;

	return newNum;
}

//this func receive a rational object return it, and add to it 1
Rational Rational::operator++(int u)
{
	Rational temp = *this;
	numerator += denominator;
	return temp;
}

//this func receive a rational object,and add to it 1, and return it
Rational Rational::operator++()
{
	numerator += denominator;
	return *this;
}

//this func receive a rational object,and sub to it 1, and return it
Rational Rational::operator--()
{
	numerator -= denominator;
	return *this;
}

//this func receive a rational object return it, and sub to it 1
Rational Rational::operator--(int u)
{
	Rational temp = *this;
	numerator -= denominator;
	return temp;
}

//this func receive a rational object, and check if it bigger or equal to another rational object if yes the func return true
//if not, false
bool Rational::operator>=(const Rational& num) const
{
	if (numerator * num.denominator >= num.numerator * denominator)
		return true;
	return false;
}

//this func receive a rational object, and check if it smaller or equal to another rational object if yes the func return true
//if not, false
bool Rational::operator<=(const Rational& num) const
{
	if (numerator * num.denominator <= num.numerator * denominator)
		return true;
	return false;
}

//this func receive a rational object, and check if it biggerto another rational object if yes the func return true
//if not, false
bool Rational::operator>(const Rational& num) const
{
	if (numerator * num.denominator > num.numerator * denominator)
		return true;
	return false;
}

//this func receive a rational object, and check if it smaller to another rational object if yes the func return true
//if not, false
bool Rational::operator<(const Rational& num) const
{
	if (numerator * num.denominator < num.numerator * denominator)
		return true;
	return false;
}

//this func receive a rational object, and check if not equal to another rational object if yes the func return true
//if not, false
bool Rational::operator!=(const Rational& num) const
{
	if (numerator * num.denominator != num.numerator * denominator)
		return true;
	return false;
}
