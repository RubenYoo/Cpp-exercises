#include "Vector.h"
#include <iostream>
using namespace std;

//Constructor of the Class
//capacity in default is set at 2, and size 0
Vector::Vector(int a)
{
	if (a > 0)
	{
		capacity = a;
		size = 0;
		data = new int[capacity];
	}
	else
	{
		cout << "ERROR" << endl;
		size = 0;
		capacity = 0;
		data = NULL;
	}
}

//Copy constructor of the Class,receive a Vector and copy
//all the data of this Vector to the current Vector
Vector::Vector(const Vector &vec)
{
	int* tmp = new int[vec.capacity];
	capacity = vec.capacity;
	size = vec.size;

	for (int i = 0; i < size; i++)
		tmp[i] = vec.data[i];

	data = tmp;
}

//Destructor of the Class, delete all the allocated memory
Vector::~ Vector()
{
	if (capacity)
		delete[] data;
}

//this func, return the capacity variable
int Vector::getCapacity()
{
	return capacity;
}

//this func, return the size variable
int Vector::getSize()
{
	return size;
}

//this func, print all the data of a Vector
void Vector::print()
{
	cout << "capacity: " << capacity << " size: " << size << " values:";

	for (int i = 0; i < size; i++)
		cout << ' ' << data[i];

	cout << endl;
}

//this func; receive a Vector and set the current Vector to
//be indentical to this Vector
void Vector::assign(Vector vec)
{
	if (capacity)
		delete[] data;

	int* tmp = new int[vec.getCapacity()];
	size = vec.getSize();
	capacity = vec.getCapacity();

	for (int i = 0; i < size; i++)
		tmp[i] = vec.data[i];

	data = tmp;
}

//this func, receive a Vector and return true if this Vector
//is equal to the current Vector, or false if he is not equal
bool Vector::isEqual(Vector vec)
{
	if (size == vec.getSize())
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i] != vec.data[i + 1])
				return false;
		}
	}
	else
	   return false;

	return true;
}

//this func, receive a index num, and return by reference the data of this index
//that in the Vector object
int& Vector::at(int index)
{
	if (index <= 0 || size < index)
	{
		cout << "ERROR" << endl;
		return data[0];
	}
	else
		return data[index];
}

//this func, receive a Vector and return the multiplication of
//this Vector and the current Vector if they size are equal, if not
//the func return -1
int Vector::strcatcat(Vector vec)
{
	if (size != vec.getSize())
	{
		cout << "ERROR" << endl;
		return -1;
	}

	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += data[i] * vec.data[i];

	return sum;
}

//this func, receive a Vector and add it to the current Vector
//and return the new Vector
Vector Vector::strnewcat(Vector vec)
{
	Vector newVec;
	int i = 0;

	newVec.size = size + vec.getSize();
	newVec.capacity = capacity + vec.getCapacity();

	int* tmp = new int[newVec.capacity];

	for (i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}

	for (int j = i, k = 0; j < vec.getSize() + i; j++, k++)
	{
		tmp[j] = vec.data[k];
	}

	newVec.data = tmp;
	return newVec;
}

//this func, clear all the data of a Vector
void Vector::clear()
{
	size = 0;
	delete[] data;
	data = new int[capacity];
}

//this func, remove the last value of the data array in a Vector object
void Vector::delLast()
{
	if (size == 0)
		cout << "ERROR" << endl;
	else
	{
		int* tmp = new int[--size];

		for (int i = 0; i < size; i++)
			tmp[i] = data[i];

		delete[] data;
		data = tmp;
	}
}

//this func, receive a value and add it to the data array in a Vector object
void Vector::insert(int val)
{
	if (size == capacity)
	{
		int* tmp = new int[capacity * 2];

		for (int i = 0; i < size; i++)
			tmp[i] = data[i];

		delete[] data;
		data = tmp;
		capacity = capacity * 2;
	}
	data[size++] = val;
}
