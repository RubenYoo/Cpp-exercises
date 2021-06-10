#include <iostream>
#include <fstream>
#include <queue>
#include "Family.h"
using namespace std;

//prototypes of all the functions
void setFile(fstream& file);
void add(fstream& file);
void del(fstream& file, int num);
void update(fstream& file, int num, queue<Family>& q);
void waiting(fstream& file, queue<Family>& q);
bool rishum(fstream& file, int famNum, int actNum);
void print(fstream& file, int num);
void inClass(fstream& file, int num);

enum choices
{
	ADD=1,DEL,UPDATE,WAITING,RISHUM,PRINT,CLASS
};

int main()
{
	queue<Family> q;											//create a queue structure with Family objects
	fstream file;													//declaring a file variable with read an write access

	//checking if the file exist
	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}

	setFile(file);													//init the file
	int choice;														
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classes\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";
	cin >> choice;													//read the choice
	while (choice)
	{
		switch (choice)
		{
		case ADD://add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;
		case DEL://delete from file
			cout << "enter number of family to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;
			try { update(file, snum, q); }
			catch (const char* msg) { cout << msg; }
			break;
		case WAITING://update the list of classes of a waiting family
			waiting(file, q);
			break;
		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try
			{
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }
			break;
		case PRINT://print the details of a specific family
			cout << "enter number of family to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case CLASS://print the details of all the families that are taking a specific class
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;
		default:
			cout << "ERROR: invalid choice\n";

		}
		cout << "\nenter 0-7:\n";
		cin >> choice;												//close the file
	}
	file.close();										
	return 0;
}

//this func, receive a file and init it with 100 default Family objects 
void setFile(fstream& file)
{
	Family fam;

	for (int i = 0; i < 100; i++)
	{
		file.write((char*)&fam, sizeof(Family));
	}
}

//this func, receive a file and add to it a Family object
void add(fstream& file)
{
	//delcaring variables
	int familyNum, memberNum, tel;
	char nameF[20];

	//read all the informations of the family
	cout << "Enter family number, family name, numbers of members, phone number:\n";
	cin >> familyNum >> nameF >> memberNum >> tel;

	//check if the family number is valid
	if (familyNum < 1 || familyNum > 100)
		throw"ERROR: Invalid family number";

	//read the place of the family num in the file
	Family temp;
	file.seekg((familyNum-1)*sizeof(Family));
	file.read((char*)&temp, sizeof(Family));

	//check if the family already exist or not
	if (temp.getFamilyNum() == familyNum)
		throw "ERROR: Family is already in the file";

	//add the family to the file
	Family fam(familyNum, nameF, memberNum, tel);
	file.seekp((familyNum-1) * sizeof(Family));
	file.write((char*)&fam, sizeof(Family));
}

//this func, receive a file and a number of family, and remove from the file the family number
void del(fstream& file, int num)
{
	//check if the family num is valid
	if (num < 1 || num > 100)
		throw "ERROR: Invalid family number";

	//deleting the family from the file
	Family temp;
	file.seekp((num-1) * sizeof(Family));
	file.write((char*)&temp, sizeof(Family));
}

//this func, receive a file and a number of family and a queue, and update the registration of the activities of this family
void update(fstream& file, int num, queue<Family>& q)
{
	//check if the family number is valid
	if (num < 1 || num > 100)
		throw "ERROR: Invalid family number";

	//read the family from the file
	Family fam;
	file.seekg((num-1) * sizeof(Family));
	file.read((char*)&fam, sizeof(Family));

	//check if the family exist in the file
	if (fam.getFamilyNum() != num)
		throw "ERROR: Family is not in the file";

	char ch;
	int counter;
	//go over the 6 activities and do a registration for all of them
	for (size_t i = 0; i < 6; i++)
	{
		cout << "Do you want to register to the " << i + 1 << " activity?\n";
		cout << "Y for yes, N for not\n";
		cin >> ch;
		if (ch == 'Y')															//if the user want to register to the activity
		{
			counter = 0;
			Family temp;

			//check if there are already 10 taken places for this activities or not
			for (size_t j = 0; j < 100; j++)
			{
				if ((num - 1) != j)
				{
					file.seekg((j) * sizeof(Family));
					file.read((char*)&temp, sizeof(Family));
					if (temp.getFamilyNum() != 0)
						if (temp.getActivities(i))
							counter++;
				}
			
			}	
			if (counter < 10)													//if the activity is not full, add the family to this activity
			{
				fam.setActivities(true, i);
				file.seekp((num-1) * sizeof(Family));
				file.write((char*)&fam, sizeof(Family));
			}
			else                                                                //if the activity is full, enter the family to the waiting queue for this specific activity
			{
				Family wait = fam;
				cout << "Sorry, no available places, we put you in the waiting list!\n";
				wait.setActivities(true, i);
				q.push(wait);
			}
		}
		else if (ch == 'N')														//if the user don't want to register to this activity
		{
			//remove the family this activity in the file
			fam.setActivities(false, i);
			file.seekp((num-1) * sizeof(Family));
			file.write((char*)&fam, sizeof(Family));
		}	
		else																	//the user didn't enter Y or N
		{
			cout << "Please enter Y or N\n";
			i--;
		}
	}
}

//this func, receive a file and a queue, and check if there are now places for register families that are in the waiting queue
void waiting(fstream& file, queue<Family> &q)
{
	int size = q.size();
	Family fam;
	int counter;
	for (size_t i = 0; i < size; i++)
	{
		//pick the first family of the queue
		fam = q.front();
		q.pop();
		
		//check which activity the family wanted to register
		for (size_t j = 0; j < 6; j++)
		{
			if (fam.getActivities(j))
			{
				counter = 0;
				Family temp;

				//check if there are now places for this activity
				for (size_t k = 0; k < 100; k++)
				{
					file.seekg((k) * sizeof(Family));
					file.read((char*)&temp, sizeof(Family));
					if (temp.getFamilyNum() != 0)
						if (temp.getActivities(j))
							counter++;
				}
				//if yes, ask the user if he want to add the family to this activity
				if (counter < 10)
				{
					char ch;
					cout << fam.getName() << " " << fam.getTelephone() << " enter Y or N: ";
					cin >> ch;

					//if yes, add the family to this activity and update the file
					if (ch == 'Y')
					{
						file.seekg((fam.getFamilyNum()-1) * sizeof(Family));
						file.read((char*)&temp, sizeof(Family));
						temp.setActivities(true, j);
						file.seekp((fam.getFamilyNum()-1) * sizeof(Family));
						file.write((char*)&temp, sizeof(Family));
					}
				}
				//if not, re-push the family in the queue
				else
					q.push(fam);
			}
		}
	}
}

//this func, receive a file and a family number, and a activity number, and return if this family is registered to that activity or not
bool rishum(fstream& file, int famNum, int actNum)
{
	//check if the family number is valid
	if (famNum < 1 || famNum > 100)
		throw "ERROR: Invalid family number";

	//check if the activity number is valid
	if (actNum < 1 || actNum > 6)
		throw"ERROR: Invalid class number";

	//read the family from the file
	Family fam;
	file.seekg((famNum-1) * sizeof(Family));
	file.read((char*)&fam, sizeof(Family));

	//check if the family exist in the file
	if (fam.getFamilyNum() != famNum)
		throw "ERROR: Family is not in the file";

	//return if the family is registered to the activity or not
	if (fam.getActivities(actNum-1))
		return true;
	return false;

}

//this func receive a file and an Family number, and print all the informations of that family
void print(fstream& file, int num)
{
	//checking if the family number is valid
	if (num < 1 || num > 100)
		throw "ERROR: Invalid family number";

	//read the family from the file
	Family temp;
	file.seekg((num-1) * sizeof(Family));
	file.read((char*)&temp, sizeof(Family));

	//checking if the family exist
	if (temp.getFamilyNum() != num)
		throw "ERROR: Family is not in the file";

	//print all the informations
	cout << "Name of family: " << temp.getName() << endl;
	cout << "Numbers of members in the family: " << temp.getMemberNum() << endl;
	cout << "Phone numbers: " << temp.getTelephone() << endl;
	
	for (int i = 0; i < 6; i++)
	{
		cout << "Activity " << i+1 << ": ";
		if (temp.getActivities(i))
			cout << "Y\n";
		else
			cout << "N\n";
	}

}

//this func receive a file and an activity number, and print all the families that are registered to that activity
void inClass(fstream& file, int num)
{
	//checking if the activity number is valid
	if (num < 1 || num > 6)
		throw"ERROR: Invalid class number";

	Family temp;

	//iterate over all the family and print the name of the families that are registered to that activity
	for (size_t i = 0; i < 100; i++)
	{
		file.seekg((i) * sizeof(Family));
		file.read((char*)&temp, sizeof(Family));
		if (temp.getFamilyNum() != 0)
		{
			if (temp.getActivities(num-1))
			{
				cout << "Family name: " << temp.getName() << endl;
			}
		}
	}
}

/*
Choices are:
0 to exit
1 to add a family
2 to delete a family
3 to update rishum to classes
4 to update waiting to classes
5 to check rishum for a classes
6 to print a family
7 to print all the families that participate in a specific class
enter 0-7:
1
Enter family number, family name, numbers of members, phone number:
1 Cohen 3 556887578

enter 0-7:
3
enter number of family to update:
1
Do you want to register to the 1 activity?
Y for yes, N for not
Y
Do you want to register to the 2 activity?
Y for yes, N for not
N
Do you want to register to the 3 activity?
Y for yes, N for not
N
Do you want to register to the 4 activity?
Y for yes, N for not
N
Do you want to register to the 5 activity?
Y for yes, N for not
N
Do you want to register to the 6 activity?
Y for yes, N for not
N

enter 0-7:
5
enter number of family to check rishum:
1
enter number of class to check rishum:
1
The family is taking the class

enter 0-7:
7
enter number of class to check rishum:
1
Family name: Cohen

enter 0-7:
6
enter number of family to print:
1
Name of family: Cohen
Numbers of members in the family: 3
Phone numbers: 556887578
Activity 1: Y
Activity 2: N
Activity 3: N
Activity 4: N
Activity 5: N
Activity 6: N

enter 0-7:
0
*/
