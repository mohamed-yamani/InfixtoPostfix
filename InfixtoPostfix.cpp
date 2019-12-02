#include <iostream>
#include "stack.h"
using namespace std;

int     findprecedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

int     main()
{
    Stack sl;
    int i, j = 0;
    char ch;
    char infinx[100], postfix[100];

    cout <<"Enter infix expression" << endl;
    cin>>infinx;
    i = 0;
    while (infinx[i++] != '\0')
        ;
    infinx[i + 1]='\0';
    infinx[i--] = ')';
    while (i>0)
    {
        infinx[i]=infinx[i - 1];
        i--;
    }
    infinx[i] = '(';
    //cout<<infinx<<endl;
    
    i = 0;
    while (infinx[i] != '\0')
    {
        if (infinx[i] == '(')
        {
            sl.push(infinx[i]);
        }
        else if (infinx[i] >= '0' && infinx[i] <= '9')
        {
            postfix[j++] = infinx[i];
        }
        else if (infinx[i] == '+' || infinx[i] == '-' || infinx[i] == '*' || infinx[i] == '/')
        {
            while (sl.peep() == '+' || sl.peep() == '-' || sl.peep() == '*' || sl.peep() == '/')
            {
                if (findprecedence(sl.peep()) >= findprecedence(infinx[i]))
                {
                    postfix[j++] = sl.pop();
                }
                else
                    break;
            }
            sl.push(infinx[i]);
        }
        else if (infinx[i] == ')')
        {
             while ((ch = sl.pop())!='(')
             {
                 postfix[j++]=ch; 
             }
        }
        i++;
    }
    postfix[i] = 0;
    cout<<postfix<<endl;
    return 0;
}