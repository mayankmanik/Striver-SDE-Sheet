#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{

    return 0;
}