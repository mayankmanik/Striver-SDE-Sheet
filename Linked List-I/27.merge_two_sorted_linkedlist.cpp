#include <bits/stdc++.h>
using namespace std;

//  You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of
// the first two lists.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ListNode *head = NULL, *tail = NULL;
    while (list1 and list2)
    {
        if (list1->val > list2->val)
        {
            if (head == NULL and tail == NULL)
            {
                head = list2;
                tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
        else
        {
            if (head == NULL and tail == NULL)
            {
                head = list1;
                tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
    }
    tail->next = list1 ? list1 : list2;
    return head;
}
int main()
{

    return 0;
}