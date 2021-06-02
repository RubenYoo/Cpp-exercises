#pragma once
#include "Queue.h"
#include "StackList.h"
class QueueStack : public Queue 
{
protected:
	//variable
    StackList data; 
public:
	//constructor
	QueueStack();
	//methods
    void clear() override;
	int dequeue() override ;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};  

