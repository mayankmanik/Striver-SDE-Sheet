#include <bits/stdc++.h>
using namespace std;

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverse(ListNode *s, ListNode *e)
{
    ListNode *p = NULL, *c = s, *n = s->next;
    while (p != e)
    {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL)
            n = n->next;
    }
}
ListNode *reverseKGroupIterative(ListNode *head, int k)
{
    if (!head or !head->next or k == 1)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *beforeStart = dummy, *e = head;
    int i = 0;
    while (e != NULL)
    {
        i++;
        if (i % k == 0)
        {
            ListNode *s = beforeStart->next, *temp = e->next;
            reverse(s, e);
            beforeStart->next = e;
            s->next = temp;
            beforeStart = s;
            e = temp;
        }
        else
        {
            e = e->next;
        }
    }
    return dummy->next;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head or !head->next or k == 1)
        return head;
    ListNode *s = head, *e = head;
    int inc = k - 1;
    while (inc--)
    {
        e = e->next;
        if (e == NULL)
            return head;
    }
    ListNode *nextHead = reverseKGroup(e->next, k);
    reverse(s, e);
    s->next = nextHead;
    return e;
}

int main()
{

    return 0;
}