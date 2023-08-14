#include <bits/stdc++.h>
using namespace std;

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.

// O(m+n)-Time Complexity O(1)-Space Complexity

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2)
    {
        l1 = !l1 ? headB : l1->next;
        l2 = !l2 ? headA : l2->next;
    }
    return l1;
}
int main()
{

    return 0;
}