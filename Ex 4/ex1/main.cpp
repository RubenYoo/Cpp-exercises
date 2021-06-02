#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
//this func, receive an Account object, and a size, and return which number of account is
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (bank[i].getAccountNumber() != number)
		throw "ERROR: no such account number!\n";

	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	else
		throw "ERROR: wrong code!\n";
}
//this func, receive an Account object and an action object and a Clock object and print the data of the Account
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
//this fun, receive an Acount object and and size and a Clock object, and print his transaction
void getBalance(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		c += 20;
		printTransaction(bank[i], balance, c);
	}
	catch (const char* msg)
	{
		cout << c << '\t' << msg;
	}
}
//this fun, receive an Acount object and and size and a Clock object, and print his deposit
void cashDeposit(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		float amount;
		cout << "enter the amount of the check: ";
		cin >> amount;
		bank[i].deposit(amount);
		c += 30;
		printTransaction(bank[i], deposit, c);
	}
	catch (const char* msg)
	{
		cout << c << '\t' << msg;
	}
}
//this fun, receive an Acount object and and size and a Clock object, and print his withdraw
void cashWithdraw(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		float amount;
		cout << "enter the amount of money to withdraw: ";
		cin >> amount;
		bank[i].withdraw(amount);
		c += 50;
		printTransaction(bank[i], withdraw, c);
	}
	catch (const char* msg)
	{
		cout << c << '\t' << msg;
	}
}

int main()
{
	//variables
	Clock c(8);
	Account bank[10];
	cout << "enter account number, code and email for 10 accounts:\n";

	//creating the 10 accounts
	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();

	//choose the actions to do on the accounts
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);			//print the balance of an account
			break;
		case withdraw:cashWithdraw(bank, 10, c);		//print the cash withdraw of an account
			break;
		case deposit:cashDeposit(bank, 10, c);			//print the cash deposit of an account
			break;	
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);	//print the sum deposit
			break;
		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);	//print the sim withdraw of an account

		}
		ac = menu();
	}
	return 0;
}
