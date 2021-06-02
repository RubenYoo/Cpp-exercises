#pragma once
class Rational
{
	//creating two private variables, and set a prototype of a private function
private:
	int x;
	int y;
	Rational reduction();
	//setting all the public prototypes of the instances of the class
public:
	void setDenominator(int denominator);
	int getDenominator();
	void setNumerator(int numerator);
	int getNumerator();
	void print();
	bool equal(Rational num);
	Rational add(Rational num);
};

