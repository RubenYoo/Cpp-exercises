#pragma once
class MyString
{
private:
	//private func of the Class
	void setMyString(const char*);

	//private variables of the Class
	int len; 
	char* array;
public:
	MyString();					//constructor
	MyString(const char*);		//constructor with value
	MyString(const MyString&);	//copy construtor
	~MyString();				//destructor

	//all the operators of the Class
	MyString& operator=(const MyString&);
	MyString operator+(const MyString&);
	char& operator[](int index) const;
	bool operator==(const MyString&) const;
	bool operator<(const MyString&) const;
	bool operator>(const MyString&) const;
	bool operator<=(const MyString&) const;
	bool operator>=(const MyString&) const;
	bool operator!=(const MyString&) const;

	//methods of the Class
	int length() { return len; }
	bool empty() { return length() == 0; }
	MyString insert(int index, const char* str);
	void print();
};