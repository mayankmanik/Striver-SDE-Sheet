#include <bits/stdc++.h>
using namespace std;

// Stack is a data structure that follows the LIFO (Last in First out) principle. Design and implement a stack.

class Stack
{
private:
    int *arr;
    int size;
    int front = -1;
    int rear = -1;

public:
    Stack(int capacity)
    {
        size = capacity;
        arr = new int[size];
    }

    void push(int num)
    {
        if (rear < size)
            arr[++rear] = num;
    }

    int pop()
    {
        if (rear == -1)
            return -1;
        return arr[rear--];
    }

    int top()
    {
        if (rear == -1)
            return -1;
        return arr[rear];
    }

    int isEmpty()
    {
        return rear == -1;
    }

    int isFull()
    {
        return rear == size;
    }
};

int main()
{

    return 0;
}