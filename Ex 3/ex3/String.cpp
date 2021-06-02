#include <iostream>
#include "MyString.h"
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

//constructor with value
MyString::MyString(const char* str)
{
	setMyString(str);
}

//constructor
MyString::MyString() : MyString("") {}

//copy constructor
MyString::MyString(const MyString& str) : MyString(str.array)
{
}

//destructor
MyString::~MyString()
{
	delete[] array;
}

//this func, receive a string and copy it into the current string, and return it
MyString& MyString::operator=(const MyString& str)
{
	if (&str != this) {
		delete[] array;

		setMyString(str.array);
	}

	return *this;
}

//this func, receive a string and add to it one char, and return it
MyString MyString::operator+(const MyString& str)
{
	int length = strlen(array) + strlen(str.array) + 1;
	char* p = new char[length];
	strcpy(p,array);
	strcat(p,str.array);

	MyString tmp(p);
	delete[] p;

	return tmp;
}

//this func, receive a num and return the value of that index in the string
char& MyString::operator[](int index) const
{
	return array[index];
}

//this func, receive a string and check if the string is equal to the current string
//if yes the func return true, if not the func return false
bool MyString::operator==(const MyString& str) const
{
	if (len == str.len)
	{
		for (int i = 0; i < len; i++)
		{
			if (((int)array[i] + 32 != (int)str.array[i] && (int)array[i] != (int)str.array[i] + 32 && (int)array[i] != (int)str.array[i]))
			{
				return false;
			}
		}
	}

	return false;
}

//this func, receive a string and check if the string is lesser to the current string
//if yes the func return true, if not the func return false
bool MyString::operator<(const MyString& str) const
{
	if (!(array == str.array))
		return strcmp(array, str.array) < 0;
	return false;
}

//this func, receive a string and check if the string is bigger to the current string
//if yes the func return true, if not the func return false
bool MyString::operator>(const MyString& str) const
{
	if (!(array == str.array))
		return strcmp(array, str.array) > 0;
	return false;
}

//this func, receive a string and check if the string is lesser or equal to the current string
//if yes the func return true, if not the func return false
bool MyString::operator<=(const MyString& str) const
{
	if ((array == str.array))
		return true;
	return strcmp(array, str.array) <= 0;
}

//this func, receive a string and check if the string is bigger or equal to the current string
//if yes the func return true, if not the func return false
bool MyString::operator>=(const MyString& str) const
{
	if ((array == str.array))
		return true;
	return strcmp(array, str.array) >= 0;
}

//this func, receive a string and check if the string is not equal to the current string
//if yes the func return true, if not the func return false
bool MyString::operator!=(const MyString& str) const
{
	return !(array == str.array);
}

// setMyString: does a deep copy
void MyString::setMyString(const char* str)
{
	// needed since strlen no longer checks for null
	if (str == NULL)
		str = "";

	len = strlen(str);
	array = new char[len + 1];
	strcpy(array,str);
}

//this func, print a string
void MyString::print()
{
	cout << array;
}

//this func, receive an index and a array of char, and add to the current
//string at the entered index, the entered array of char, and return the new string
MyString MyString::insert(int index, const char* str)
{
	MyString newStr;
	int lenght = strlen(str);
	
	if (index < 0 || index > lenght)
	{
		cout << "ERROR\n";
		newStr.len = 0;
		return newStr;
	}

	newStr.len = len + lenght + 1;
	char* array = new char[newStr.len];

	for (int i = 0; i < index; i++)
		array[i] = this->array[i];

	array[index] = '\0';
	strcat(array, str);

	for (int i = index; i < this->len; i++)
		array[i+lenght] = this->array[i];

	array[lenght+len] = '\0';

	newStr.array = array;
	array = NULL;

	return newStr;
}
