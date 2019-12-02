#include <iostream>
#include"stack.h"
using namespace std;

Stack ::Stack()
{
    top = -1;
} 

void    Stack::push(int data)
{
    if(!isfull())
        arr[++top] = data;
    else
        throw "overflow!!!";
}

int     Stack::pop()
{
    if(!isempty())
        return (arr[top--]);
    else
        throw "underflow!!!";
}

int     Stack::peep()
{
    if(!isempty())
        return (arr[top]);
    else
        throw "underflow!!!";
}

bool    Stack::isfull()
{
    return top == size - 1;
}

bool    Stack::isempty()
{
    return top == -1;
}