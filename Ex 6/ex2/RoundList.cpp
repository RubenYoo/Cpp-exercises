#include "RoundList.h"

//constructor
RoundList::RoundList() : List()
{}

//this func, receive a val and add it in a link in the beginnig of the List
void RoundList::add(int val)
{
    if (isEmpty())
    {
        List::add(val);
        head->next = head;
    }
    else
    {
        Link* p = head;

        while (p->next != head)
        {
            p = p->next;
        }

        p->next = new Link(val, head);
        head = p->next;
    }
}

//this func, clear the list
void RoundList::clear()
{
    // empty all elements from the List
    Link* theNext;
    for (Link* p = head->next; p != head; p = theNext)
    {
        // delete the element pointed to by p
        theNext = p->next;
        p->next = NULL;
        delete p;
    }
    delete head;
    head = NULL;
}

//this func, remove the first link of the list
void RoundList::removeFirst()
{
    if (!isEmpty() && head != head->next)
    {
        Link* p1 = head;
        Link* p2 = head;

        while (p2->next != head)
        {
            p2 = p2->next;
        }

        p2->next = head->next;
        head = p1->next;
        p1->next = NULL;

        delete p1;
    }
    else if(!isEmpty() && head == head->next)
    {
        head->next = NULL;
        delete head;
        head = NULL;
    }
}

//this func, receive a num, and return the value of the num position in the list
int RoundList::search(int n)
{
    if (isEmpty() || n < 0)
        return -1;

    Link* p = head;

    for (int i = 0; i < n; i++)
        p = p->next;

    return p->value;
    
}

//this func, receive a val, and add it to the end of the list
void RoundList::addToEnd(int val)
{
    if (isEmpty())
    {
        add(val);
    }
    else
    {
        Link* p = head;

        while (p->next != head)
        {
            p = p->next;
        }

        p->next = new Link(val, head);
    }
        
}
