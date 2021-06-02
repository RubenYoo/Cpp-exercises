#pragma once
#include "Queue.h"

template <class T>
class QueueVector : public Queue<T>
{
public:
	//constructor
	QueueVector(int max);
	//methods
	void clear() override;
	T dequeue() override;
	void enqueue(T value) override;
	T front() override;
	bool isEmpty() const override;
private:
	//privates variables
	T* data;
	int capacity;
	int nextSlot;
	int firstUse;
};
//constructor
template <class T>
QueueVector<T>::QueueVector(int size) {
	capacity = size + 1;
	data = new T[capacity];
	clear();
}
//the func clear the queue
template <class T>
void QueueVector<T>::clear() {
	nextSlot = 0;
	firstUse = 0;
}
//this func return and remove the first element of the queue
template <class T>
T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];
}
//this func receive a val and add it to the queue
template <class T>
void QueueVector<T>::enqueue(T val) {
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}
//this func return the first value of the queue
template <class T>
T QueueVector<T>::front() {
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}
//thsi func return if the queue is empty or not
template <class T>
bool QueueVector<T>::isEmpty() const {
	return nextSlot == firstUse;
}
