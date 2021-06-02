#include "Library.h"
#include <iostream>
using namespace std;

//this operator return true of two Library objects are equal and false if not
bool Library::operator==(Library& lb) const
{
    if (code == lb.code && author == lb.author && book == lb.book)
        return true;
    return false;
}
//this operator return false of two Library objects are equal and true if not
bool Library::operator!=(Library& lb) const
{
    return!(*this == lb);
}
//this operator return true the current library object is bigger than the received library object
bool Library::operator>(Library& lb) const
{
    if (author == lb.author)
    {
        if (book == lb.book)
        {
            if (code == lb.code)
                return false;
            else
                return code > lb.code;
        }
        else
            return book > lb.book;
    }
    else
        return author > lb.author;
}
//this operator return true the current library object is smaller than the received library object
bool Library::operator<(Library& lb) const
{
    if (author == lb.author)
    {
        if (book == lb.book)
        {
            if (code == lb.code)
                return false;
            else
                return code < lb.code;
        }
        else
            return book < lb.book;
    }
    else
        return author < lb.author;
}
//this operator return true the current library object is smaller or equal than the received library object
bool Library::operator<=(Library& lb) const
{
    if (*this == lb)
        return true;
    return (*this < lb);
}
//this operator return true the current library object is bigger or equal than the received library object
bool Library::operator>=(Library& lb) const
{
    if (*this == lb)
        return true;
    return (*this > lb);
}

//operator >> 
istream& operator>>(istream& is, Library& lb)
{
    cin >> lb.code;
    cin >> lb. author;
    cin >> lb.book;

    return is;

}
//operator <<
ostream& operator<<(ostream& os, const Library& lb)
{
    cout << lb.code << ' ' << lb.author << ' ' << lb.book << endl;

    return os;
}
