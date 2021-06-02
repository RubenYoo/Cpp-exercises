#pragma once
class Vector
{
	//declaring all the private variables
	int* data;
	int capacity;
	int size;
public:
	Vector(int a = 2);                 //constructor
	Vector(const Vector &vec);         //copy constructor
	~ Vector();                        //destructor
	//all the methods of the class
	int getCapacity();
	int getSize();
	void print();
	void assign(Vector);
	bool isEqual(Vector);
	int& at(int index);
	int strcatcat(Vector);
	Vector strnewcat(Vector);
	void clear();
	void delLast();
	void insert(int val);
};

