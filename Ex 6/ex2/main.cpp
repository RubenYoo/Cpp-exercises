#include <iostream>
#include "RoundList.h"
using namespace std;

enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};

int main() {

	//creating the round list
	RoundList ls1;
	int choice;

	cout << "Enter your choice: ";
	cin >> choice;										//read what the user want to do with the Round List

	while (choice != EXIT)								//if the choice is 0 exit
	{
		int num;
		switch (choice) {
		case ADD: 	cout << "Enter 5 numbers: ";		//add 5 num in the beginning of the list
			for (int i = 0; i < 5; i++)
			{
				cin >> num;
				ls1.add(num);
			}
			break;

		case ADD_TO_END:cout << "Enter 5 numbers: ";	//add 5 num in the end of the list
			for (int i = 0; i < 5; i++)
			{
				cin >> num;
				ls1.addToEnd(num);
			}
			break;

		case REMOVE_FIRST: ls1.removeFirst();			//remove first link of the list
			break;
				
		case SEARCH: cout << "Enter a number: ";		//print the val of the num position in the list
			cin >> num;
			cout << ls1.search(num) << endl;
			break;

		case CLEAR: ls1.clear();						//clear all the list
			break;

		case EMPTY: if (ls1.isEmpty())					//check if the list is empty or not
			cout << "Empty" << endl;
				  else
			cout << "Not empty" << endl;
			break;

		default: cout << "ERROR!" << endl;				//check if the input choice is valid
		}
		cout << "Enter your choice: ";
		cin >> choice;
	}
	return 0;
}

/*
Enter your choice: 1                                                            
Enter 5 numbers: 1 2 3 4 5                                                      
Enter your choice: 2                                                            
Enter 5 numbers: 5 4 3 2 1                                                      
Enter your choice: 3                                                            
Enter your choice: 4                                                            
Enter a number: 2                                                               
2                                                                               
Enter your choice: 3                                                            
Enter your choice: 4                                                            
Enter a number: 2                                                               
1                                                                               
Enter your choice: 4                                                            
Enter a number: 6                                                               
2                                                                               
Enter your choice: 6                                                            
Not empty                                                                       
Enter your choice: 5                                                            
Enter your choice: 6                                                            
Empty                                                                           
Enter your choice: 0    
*/
