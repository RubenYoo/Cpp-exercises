#include <iostream>
#include "Rational.h"                                     

using namespace std;

int main()
{
	//declaring all the variables
	int numerator, denominator;
	char tav;
	Rational r1, r2;

	cout << "enter two rational numbers:" << endl;

	cin >> numerator >> tav >> denominator;                //reading from the user the first rational num
	r1.setNumerator(numerator);                            //set it into 
	r1.setDenominator(denominator);                        //an object

	cin >> numerator >> tav >> denominator;                //reading from the user the second rational num
	r2.setNumerator(numerator);                            //set it into
	r2.setDenominator(denominator);                        //an object

	Rational ans = r1.add(r2);                             //delcaring a new rational num that is the sum of the 2 nums

	r1.print();                                            //printing the first rational num
	cout << "+ ";
	r2.print();                                            //printing the second rational num
	cout << "= ";
	ans.print();                                           //printing the sum
	cout << endl;

	if (r1.equal(r2))                                      //checking of the two rational num are equal
		cout << "The two numbers are equal" << endl;
	else
	{
		cout << "The two numbers are different" << endl;

		r1.print();
		r2.print();

		cout << endl;
	}
	return 0;
}
/*
enter two rational numbers:
1/2 2/6
1/2 +  2/6 = 5/6
The two numbers are different
1/2  2/6
*/