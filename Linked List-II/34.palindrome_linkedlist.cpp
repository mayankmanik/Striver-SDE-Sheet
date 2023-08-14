#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// O(1)-Space Complexity

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head, *prev, *temp;
    while (fast && fast->next)      // finding middle of linkedlist
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    prev = slow;
    slow = slow->next;
    prev->next = NULL;
    while (slow)        // reversing the part after middle node
    {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    fast = head, slow = prev;
    while (slow)
    {
        if (fast->val != slow->val)
            return false;
        else
            fast = fast->next, slow = slow->next;
    }
    return true;
}

int main()
{

    return 0;
}