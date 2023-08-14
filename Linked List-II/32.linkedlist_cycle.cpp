#include <bits/stdc++.h>
using namespace std;

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *front = head, *tail = head;
    while (tail and tail->next)
    {
        front = front->next;
        tail = tail->next->next;
        if (front == tail)
            return true;
    }
    return false;
}

int main()
{

    return 0;
}