#include <iostream>
#include "QueueStack.h"
using namespace std;
int main() {

	//declaring a queue
	Queue* Q;
	Q = new QueueStack();

	//enter the nums into the queue
	try {
		for (int i = 0; i < 10; i++)
			Q->enqueue(i);
	}
	catch (const char* msg)
	{
		cout << msg;
	}

	//print the first element in the queue
	cout << "first on Q is: " << Q->front() << endl;
	//delete and print two elements
	cout << "take out 2 elemets:" << endl;
	cout << Q->dequeue() << ' ' << Q->dequeue() << endl;
	//print the first element in the queue
	cout << "first on Q is: " << Q->front() << endl;
	//push 8 and 9 into the queue
	Q->enqueue(8);
	Q->enqueue(9);
	//print and delete all the queue
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	return 0;
}
/*
first on Q is: 0
take out 2 elemets:
0 1
first on Q is: 2
2 3 4 5 6 7 8 9 8 9
*/
