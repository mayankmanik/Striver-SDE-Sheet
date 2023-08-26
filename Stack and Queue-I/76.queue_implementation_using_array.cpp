#include <bits/stdc++.h>
using namespace std;

// Queue is a data structure that follows the FIFO (First in First out) principle.
// Implement a Queue Data Structure specifically to store integer data using an array.

class Queue
{
private:
    int size = 10000;
    int frontt = -1;
    int rear = -1;
    int *arr;

public:
    Queue()
    {
        arr = new int[size];
    }

    bool isEmpty()
    {
        return (frontt == -1 or frontt > rear);
    }

    void enqueue(int data)
    {
        if (frontt == -1)
            frontt++;
        arr[++rear] = data;
    }

    int dequeue()
    {
        if (frontt == -1 or frontt > rear)
            return -1;
        int x = arr[frontt++];
        return x;
    }

    int front()
    {
        if (frontt == -1 or frontt > rear)
            return -1;
        return arr[frontt];
    }
};

int main()
{

    return 0;
}