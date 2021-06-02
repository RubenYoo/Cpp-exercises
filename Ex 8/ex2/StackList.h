 #pragma once
 #include "List.h"	
 #include "Stack.h"

//-------------------------------------------------------
//  class StackList
//  Stack implemented using List operations
//-------------------------------------------------------

class StackList : public Stack  
{
public:
    // constructors
    StackList();
    StackList(const StackList& s);

    // Stack operations
     void clear() override;
     bool isEmpty() const override;
     int pop() override;
     void push(int value) override;
     int top() const override;

protected:
    // data fields
    List data;
};