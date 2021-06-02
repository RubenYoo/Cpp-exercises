#pragma once
class Rational
{
	//creating two private variables
private:
	int numerator;
	int denominator;
public:
	//constructor
	Rational(int, int);

	//setting all the public methods of the class
	Rational reduction();
	void setDenominator(int denominator);
	int getDenominator() const;
	void setNumerator(int numerator);
	int getNumerator() const;
	void print();

	//all the operators
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator/(const Rational&);
	Rational operator*(const Rational&);
	Rational operator++(int u);
	Rational operator++();
	Rational operator--();
	Rational operator--(int u);
	bool operator==(const Rational&) const;
	bool operator>=(const Rational&) const;
	bool operator<=(const Rational&) const;
	bool operator>(const Rational&) const;
	bool operator<(const Rational&) const;
	bool operator!=(const Rational&) const;
};
