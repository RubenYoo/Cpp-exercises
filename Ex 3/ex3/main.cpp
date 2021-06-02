#include <iostream>
#include "MyString.h"
#include<cstring>
using namespace std;

int main() {

	//declaring variables
	char temp1[50], temp2[50];
	int num;

	//reading the strings
	cin >> temp1;
	cin >> temp2;

	//setting the strings
	MyString str1(temp1);
	MyString str2(temp2);

	//read the num
	cin >> num;

	//check if the two strings are equal biggger or lesser one to the other
	if (str1 == str2)
		cout << "a=b\n";
	else if(str1 > str2)
		cout << "a>b\n";
	else if(str1 < str2)
		cout << "a<b\n";
	
	//creating a new string with the two old strings
	MyString str3 = str2.insert(num, temp1);

	//print the new string
	str3.print();

	if (str3.length() > 0)
		cout << '\n';

	//declaring new variables
	char tav;
	int index;

	//read the tav and the index
	cin >> tav >> index;

	//add it to the string if it's valid, and print the string
	if (str3.length() > 0 && index + 1 < str3.length())
	{
		str3[index] = tav;
		str3.print();
	}
	//if not valid print ERROR
	else if(!(str1 == str2))
		cout << "ERROR";

	return 0;
}
