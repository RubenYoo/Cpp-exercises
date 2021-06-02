#include"Rational.h"
#include <iostream>
using namespace std;

enum { add, sub, mult, divi, addPre, addPost, subPre, subPost, big, small, bigEq, smallEq, eequal, notEqual };
int main()
{
	//declaring the variables
	int numerator, denominator;
	char tav;
	int op = 1;

	while (op != 0)
	{
		cout << "enter two rational numbers:" << endl;
		cin >> numerator >> tav >> denominator;
		Rational r1(numerator, denominator);          //creating the first rational num
		cin >> numerator >> tav >> denominator;
		Rational r2(numerator, denominator);          //creating the second rational num
		switch (0)
		{
			//print the sum of 2 rational num
		case add:r1.print(); cout << " + "; r2.print(); cout << " = "; (r1 + r2).print(); cout << endl;

			//print the sub of 2 rational num
		case sub:r1.print(); cout << " - "; r2.print(); cout << " = "; (r1 - r2).print(); cout << endl;

			//print the multiplication of 2 rational num
		case mult:r1.print(); cout << " * "; r2.print(); cout << " = "; (r1 * r2).print(); cout << endl;

			//print the ratio of 2 rational num
		case divi:r1.print(); cout << " / "; r2.print(); cout << " = "; (r1 / r2).print(); cout << endl;

			//print the rational num + 1
		case addPre:cout << "++"; cout << "("; r1.print();  cout << ") = "; (++r1).print(); cout << endl;

			//print the rational num + 1
		case addPost: cout << "("; r1.print(); cout << ")++"; cout << " = "; (r1++).print(); cout << endl;

			//print the rational num - 1
		case subPre:cout << "--"; cout << "("; r1.print();  cout << ") = "; (--r1).print(); cout << endl;

			//print the rational num - 1
		case subPost:cout << "("; r1.print(); cout << ")--"; cout << " = "; (r1--).print(); cout << endl;

			//print which rational num is bigger
		case big:r1.print(); cout << " > "; r2.print(); cout << " ? ";  (r1 > r2) ? cout << "yes" : cout << "no"; cout << endl;

			//print which rational num is smaller
		case small:r1.print(); cout << " < "; r2.print(); cout << " ? ";  (r1 < r2) ? cout << "yes" : cout << "no"; cout << endl;

			////print which rational num is bigger or equal
		case bigEq:r1.print(); cout << " >= "; r2.print(); cout << " ? ";  (r1 >= r2) ? cout << "yes" : cout << "no"; cout << endl;

			//print which rational num is smaller or equal
		case smallEq:r1.print(); cout << " <= "; r2.print(); cout << " ? ";  (r1 <= r2) ? cout << "yes" : cout << "no"; cout << endl;

			//print if the rational num are equal
		case eequal:r1.print(); cout << " == "; r2.print(); cout << " ? ";  (r1 == r2) ? cout << "yes" : cout << "no"; cout << endl;

			//print if the rational num are not equal
		case notEqual:r1.print(); cout << " != "; r2.print(); cout << " ? ";  (r1 != r2) ? cout << "yes" : cout << "no"; cout << endl;

		}
		cout << "enter 1 to cont. 0 to exit." << endl;
		cin >> op;
	}

	return 0;
}
