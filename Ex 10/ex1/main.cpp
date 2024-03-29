#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <algorithm>
#include "Soldier.h"
#include "Private.h"
#include "Commander.h"
#include "Officer.h"
using namespace std;

enum option {
	stop,	//	סיום התוכנית
	addNewSoldier,	//	הוספת חייל חדש
	medalList,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	mostSociometric,	//	הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	countMedalPrivate,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	noCombatCommander,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	overSoldier,	//	הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	removeOfficer,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};

void add(vector<Soldier*> &vec);    
void medal(vector<Soldier*> vec);   
Soldier* mostSociometricScore(vector<Soldier*> vec);   

int main()
{
	vector<Soldier*> vec;  // הצהרה על ווקטור או רשימה של חיילים
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewSoldier:
			try
			{
				add(vec);  //הוספת חייל חדש						
			}
			catch (const char* str)
			{
				cout << str;
			}
			break;
		case medalList:medal(vec);  //הדפסת פרטי הזכאים לצל"ש
			break;
		case mostSociometric:   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
		{
			Soldier* s = mostSociometricScore(vec);
			cout << "Officer soldier with most sociometric score: ";
			if (s != NULL) cout << s->getFname() << ' ' << s->getName();
			cout << endl;
			break;
		}
		case countMedalPrivate:  cout << "# private soldier for medal: ";
		{
			int sum = [&vec]()->int {int count = 0; for_each(vec.begin(), vec.end(), [&count](Soldier* s) {if (s->medal() && s->soldierType() == "private") count++; }); return count; }(); //הדפסת מספר הזכאים לצל"ש בטירונים
			cout << sum << endl;
			break;
		}
		case noCombatCommander: cout << "list of no combat commander soldier :";
			//הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			for_each(vec.begin(), vec.end(), [](Soldier* s) {if (!s->getCombat()) cout << s->getFname() << ' ' << s->getName() << endl; });
			cout << endl;
			break;
		case overSoldier:
			if (any_of(vec.begin(), vec.end(), [](Soldier* s)->int {return s->getNumOp() >= 15; })) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים
				cout << "there is a soldier that takes more than 15 operations\n";
			else cout << "no soldier takes more than 15 operations\n";
			break;
		case removeOfficer:
		{
			//מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			auto end = remove_if(vec.begin(), vec.end(), [](Soldier* s) {return (s->getNumOp() == 0) && (s->soldierType() == "officer"); });
			for_each(vec.begin(), end, [](Soldier* s) {s->print(); }); //הדפסת כל הרשימה לאחר מחיקת האיברים
			break;
		}
		}
		cout << "enter 0-7\n";
		cin >> op;
	}
}


//this func, receive a vector of Soldiers pointers, and add to it a new soldier
void add(vector<Soldier*> &vec)
{
	//declaring all the variables
	int soldier, id, numOfOperations;
	string firstName, lastName;

	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";
	cin >> soldier;

	if (soldier < 1 || soldier > 3)
		throw "Please enter a num between 1 and 3 included\n";

	cout << "enter id, first name, last name and number Of operations\n";
	cin >> id >> firstName >> lastName >> numOfOperations;

	if (soldier == 1)
		vec.push_back(new Private(id, firstName, lastName, numOfOperations));
	else if (soldier == 2)
		vec.push_back(new Commander(id, firstName, lastName, numOfOperations));
	else
		vec.push_back(new Officer(id, firstName, lastName, numOfOperations));
	
}

//this func, receive a vector of Soldiers pointers, and print all the soldier that have a medal
void medal(vector<Soldier*> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->medal())
			vec[i]->print();
	}
}

//this func, receive a vector of Soldiers pointers, and calculate which officer have the best socio score, and return it
Soldier* mostSociometricScore(vector<Soldier*> vec)
{
	int socio = -1;
	int index = -1;

	//run on all of the vector
	for (int i = 0; i < vec.size(); i++)
	{
		try
		{
			//if the socio score of the current officer is bigger than the last one, swap it
			if (vec[i]->getSocio() > socio)
			{
				socio = vec[i]->getSocio();
				index = i;
			}
			
		}
		catch (const char *str)
		{
		}
	}
	//the vector have an officer
	if (index != -1)
		return vec[index];
	//no officer in the vector
	return NULL;
}

/*
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
333 ccc ccc 0
enter number of sociometric score
100
enter 0-7
3
Officer soldier with most sociometric score: ccc ccc
enter 0-7
4
# private soldier for medal: 0
enter 0-7
5
list of no combat commander soldier :
enter 0-7
6
no soldier takes more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
ID: 222
first name: bbb
last name: bbb
num operations: 0
grades:
combat: yes
enter 0-7
0
*/
