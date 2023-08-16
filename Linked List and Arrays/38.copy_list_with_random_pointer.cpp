#include <bits/stdc++.h>
using namespace std;

/*
A linked list of length n is given such that each node contains an additional random pointer,
which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
where each new node has its value set to the value of its corresponding original node. 
Both the next and random pointer of the new nodes should point to new nodes in the copied list 
such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.
*/

// O(1)-Space Complexity

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *iter = head;
    Node *front = head;

    while (iter != NULL)
    {
        front = iter->next;
        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
            iter->next->random = iter->random->next;
        iter = iter->next->next;
    }

    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;

    while (iter != NULL)
    {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return pseudoHead->next;
}
int main()
{

    return 0;
}