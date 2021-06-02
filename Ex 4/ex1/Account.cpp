#include "Account.h"
#include <iostream>
using namespace std;

//init the static variables
int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

//constructors without parameters
Account::Account()
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = "\0";
}

//constructos with parameters
Account::Account(int number = 0, int pass = 0, float bal = 0, string str = "\0")
{
	if (pass < 1000 || pass > 9999)
		throw "ERROR: wrong code!\n";

	if (str.find(".com") == std::string::npos && str.find(".co.il") == std::string::npos || str.find('@') == std::string::npos || str.find(' ') != std::string::npos)
		throw "ERROR: wrong email!\n";

	accountNumber = number;
	code = pass;
	balance = bal;
	mail = str;
}

//this func, return the account number
int Account::getAccountNumber() const
{
	return accountNumber;
}

//this func, return the code of the account
int Account::getCode() const
{
	return code;
}

//this func, return the balance of the account
float Account::getBalance() const
{
	return balance;
}

//tjis func, receive a num and substract it from the balance
void Account::withdraw(float nis)
{
	if ((balance - nis) < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";

	balance -= nis;
	sumWithdraw+=nis;
}

//this func, receive a num and add it to the balance
void Account::deposit(float dep)
{
	if (dep > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!\n";

	balance = +dep;
	sumDeposit+=dep;
}

//this func, return the static variable sumWithdraw
int Account::getSumWithdraw()
{
	return sumWithdraw;
}

//this func, return the static variable sumDeposit
int Account::getSumDeposit()
{
	return sumDeposit;
}

//operator >>, receive a istream object and account object, and return an istream object
istream& operator>>(istream& is, Account& acc)
{
	int number, pass;
	string mail;

	cin >> number >> pass >> mail;

	if (mail.find(".com") == std::string::npos && mail.find(".co.il") == std::string::npos)
		throw "ERROR: email must end at .com or .co.il!\n";

	if (mail.find('@') == std::string::npos)
		throw "ERROR: email must contain @!\n";

	if (pass < 1000 || pass > 9999)
		throw "ERROR: code must be of 4 digits!\n";


	acc.accountNumber = number;
	acc.code = pass;
	acc.mail = mail;

	return is;
}

