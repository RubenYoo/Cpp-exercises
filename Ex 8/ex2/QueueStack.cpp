#include "QueueStack.h"
#include "StackList.h"
#include "Stack.h"
#include "Queue.h"

//constructor
QueueStack::QueueStack() : data()
{
    // no further initialization
}

//this func clear the queue
void QueueStack::clear()
{
    data.clear();
}

//this func, remove the first entered element, and return it
int QueueStack::dequeue()
{
    return data.pop();
}

//this func, enter an element in the queue
void QueueStack::enqueue(int value)
{
    if(data.isEmpty())
        data.push(value);
    else
        { 
            StackList stk;
            while(!data.isEmpty())
            {
                stk.push(dequeue());
            }
            data.push(value);
            while(!stk.isEmpty())
            {
                data.push(stk.pop());
            }
        }
}

//this func, return the front element in the queue
int QueueStack::front()
{
    int tmp = dequeue();
    QueueStack qtk;
    while(!data.isEmpty())
    {
       qtk.enqueue(dequeue());
    }
    enqueue(tmp);
    while(!qtk.isEmpty())
    {
        enqueue(qtk.dequeue());
    }
    return tmp;
}

//this func, return true if the queue is emmpty and false if not
bool QueueStack::isEmpty() const
{
    return data.isEmpty();
}