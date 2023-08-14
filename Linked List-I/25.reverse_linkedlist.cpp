#include <bits/stdc++.h>
using namespace std;

//  Given the head of a singly linked list, reverse the list, and return the reversed list.

// Both recursive and iterative solution

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (!head or head->next == nullptr)
        return head;
    ListNode *temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

ListNode *reverseListIterative(ListNode *head)
{
    ListNode *prev = NULL, *temp = NULL, *curr = head;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
int main()
{

    return 0;
}