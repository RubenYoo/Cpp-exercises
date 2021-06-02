#pragma once
#include <string>
#include<iostream>
using namespace std;

class Account
{
	//private variables of the class
	int accountNumber;				
	int code;
	float balance;
	string mail;

public:
	//constructors
	Account();
	Account(int, int, float, string);

	//gets methods
	int getAccountNumber() const;
	int getCode() const;
	float getBalance() const;

	//methods of the class
	void withdraw(float);
	void deposit(float);

	//static variables
	static int sumWithdraw;
	static int sumDeposit;

	//static methods
	static int getSumWithdraw();
	static int getSumDeposit();

	//operator >>
	friend istream& operator>>(istream& is, Account& acc);
};

