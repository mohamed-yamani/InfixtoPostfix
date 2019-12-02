#define size 50

class Stack
{
    int arr[size];
    int top;
    public:
    Stack();
    void push (int);
    int pop();
    int peep();
    bool isfull();
    bool isempty();
} ;