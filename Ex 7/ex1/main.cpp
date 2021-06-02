#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangular.h"
#include "Rectangle.h"
using namespace std;

enum shapes
{
	Circle1 = 1,Triangular3 = 3,Rectangle4 = 4
};

int main()
{
	//declaring all the variables
	Shape** list = nullptr;
	int shapes;

	cout << "How many shapes you would like to define?\n";
	cin >> shapes;													//read the numbers of shapes
	list = new Shape*[shapes];
	
	for (int i = 0; i < shapes; i++)
	{
		int choice;
		cout << "Which shape will you choose ? Circle - 1, Triangular - 3, Rectangle - 4\n";

		cin >> choice;												//read the choice

		switch (choice)
		{
		case Circle1:												//if the shape is a circle
		{
			int radius;
			cout << "Enter radius: \n";
			cin >> radius;											//read the radius
			list[i] = new Circle(radius);							//create new circle object
			break;
		}
		case Triangular3:											//if the shape is a trinagle
		{
			list[i] = new Triangular();								//create new trangle
			break;
		}
		case Rectangle4:											//if the shape is a rectangle
		{
			list[i] = new Rectangle();								//create new rectangle
			break;
		}
		default:
		{	
			cout << "invalid input\n";								//if the input is invalid
			i--;													//do a loop once more
		}
		}
	}

	//loop that print the area of all the shapes, and also print if the shape is special
	for (int i = 0; i < shapes; i++)
	{
		cout << endl << *list[i] << "area is: " << list[i]->area() << endl;;	//print the area of the shape

		if (list[i]->isSpecial())												//if the shape is special
			list[i]->printSpecial();											//print the speciality
	}

	delete[] list;

	return 0;
}
/*
How many shapes you would like to define?
3
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle � 4
3
Enter values of  3 points:
(0,0) (1,0) (1,1)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle � 4
1
Enter radius:
4
Enter values of  1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle � 4
2
invalid input
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle � 4
4
Enter values of  4 points:
(0,0) (1,0) (1,1) (0,1)

points: (0,0) (1,0) (1,1)  area is: 0.5

points: (0,0) area is: 50.24
A canonical circle with a radius 4

points: (0,0) (1,0) (1,1) (0,1)  area is: 1
Square with side length 1
*/
