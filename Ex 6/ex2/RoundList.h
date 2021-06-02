#pragma once
#include "List.h"

class RoundList : public List
{
public:
    // constructors
    RoundList();

    // override the following methods from class List
    void add(int value);
    void clear();
    void removeFirst();
    int search(int);
    // add a new element to the end of the List
    void addToEnd(int value);
};

