#include <iostream>
#include <fstream>
#include <queue>
#include "Family.h"
using namespace std;

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
	//cout << sizeof(Family);
	queue<Family> q;
	fstream file;
	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";
	cin >> choice;
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
		cin >> choice;
	}
	file.close();
	return 0;
}

void setFile(fstream& file)
{
	Family fam;

	for (int i = 0; i < 100; i++)
	{
		file.write((char*)&fam, sizeof(Family));
	}
}

void add(fstream& file)
{
	int familyNum, memberNum, tel;
	char nameF[20];

	cout << "Enter family number, family name, numbers of members, phone number:\n";
	cin >> familyNum >> nameF >> memberNum >> tel;
	if (familyNum < 1 || familyNum > 100)
		throw"ERROR: Invalid family number";

	Family temp;
	file.seekg((familyNum)*sizeof(Family));
	file.read((char*)&temp, sizeof(Family));

	if (temp.getFamilyNum() == familyNum)
		throw "ERROR: Family is already in the file";

	Family fam(familyNum, nameF, memberNum, tel);
	file.seekp((familyNum) * sizeof(Family));
	file.write((char*)&fam, sizeof(Family));
}

void del(fstream& file, int num)
{
	if (num < 1 || num > 100)
		throw "ERROR: Invalid family number";

	Family temp;
	file.seekp((num) * sizeof(Family));
	file.write((char*)&temp, sizeof(Family));
}
void update(fstream& file, int num, queue<Family>& q)
{
	if (num < 1 || num > 100)
		throw "ERROR: Invalid family number";

	Family fam;
	file.seekg((num) * sizeof(Family));
	file.read((char*)&fam, sizeof(Family));

	if (fam.getFamilyNum() != num)
		throw "ERROR: Family is not in the file";

	char ch;
	int counter;
	for (size_t i = 0; i < 6; i++)
	{
		cout << "Do you want to register to the " << i + 1 << " activity?\n";
		cout << "Y for yes, N for not\n";
		cin >> ch;
		if (ch == 'Y')
		{
			counter = 0;
			Family temp;
			for (size_t j = 0; j < 100; j++)
			{
				file.seekg((j) * sizeof(Family));
				file.read((char*)&temp, sizeof(Family));
				if (temp.getFamilyNum() != 0)
					if (temp.getActivities(num))
						counter++;
			
			}
			if (counter < 10)
			{
				fam.setActivities(true, i);
				file.seekp((num) * sizeof(Family));
				file.write((char*)&fam, sizeof(Family));
			}
			else
			{
				Family wait = fam;
				cout << "Sorry, no available places, we put you in the waiting list!\n";
				wait.setActivities(true, i);
				q.push(wait);
			}
		}
		else if (ch == 'N')
		{
			fam.setActivities(false, i);
			file.seekp((num) * sizeof(Family));
			file.write((char*)&fam, sizeof(Family));
		}
	}
}
void waiting(fstream& file, queue<Family> &q)
{
	int size = q.size();
	Family fam;
	int counter;
	for (size_t i = 0; i < size; i++)
	{
		fam = q.front();
		q.pop();
		
		for (size_t j = 0; j < 6; j++)
		{
			if (fam.getActivities(j))
			{
				counter = 0;
				Family temp;
				for (size_t k = 0; k < 100; k++)
				{
					file.seekg((k) * sizeof(Family));
					file.read((char*)&temp, sizeof(Family));
					if (temp.getFamilyNum() != 0)
						if (temp.getActivities(j))
							counter++;
				}
				if (counter < 10)
				{
					char ch;
					cout << fam.getName() << " " << fam.getTelephone() << " enter Y or N: ";
					cin >> ch;
					if (ch == 'Y')
					{
						file.seekg((fam.getFamilyNum()) * sizeof(Family));
						file.read((char*)&temp, sizeof(Family));
						temp.setActivities(true, j);
						file.seekp((fam.getFamilyNum()) * sizeof(Family));
						file.write((char*)&temp, sizeof(Family));
					}
				}
				else
					q.push(fam);
			}
		}
	}
}
bool rishum(fstream& file, int famNum, int actNum)
{
	if (famNum < 1 || famNum > 100)
		throw "ERROR: Invalid family number";

	if (actNum < 1 || actNum > 6)
		throw"ERROR: Invalid class number";

	Family fam;
	file.seekg((famNum) * sizeof(Family));
	file.read((char*)&fam, sizeof(Family));

	if (fam.getFamilyNum() != famNum)
		throw "ERROR: Family is not in the file";

	if (fam.getActivities(actNum))
		return true;
	return false;

}
void print(fstream& file, int num)
{
	if (num < 1 || num > 100)
		throw "ERROR: Invalid family number";

	Family temp;
	file.seekg((num) * sizeof(Family));
	file.read((char*)&temp, sizeof(Family));

	if (temp.getFamilyNum() != num)
		throw "ERROR: Family is not in the file";

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
void inClass(fstream& file, int num)
{
	if (num < 1 || num > 6)
		throw"ERROR: Invalid class number";

	Family temp;

	for (size_t i = 0; i < 100; i++)
	{
		file.seekg((i) * sizeof(Family));
		file.read((char*)&temp, sizeof(Family));
		if (temp.getFamilyNum() != 0)
		{
			if (temp.getActivities(num))
			{
				cout << "Family name: " << temp.getName();
			}
		}
	}
}
