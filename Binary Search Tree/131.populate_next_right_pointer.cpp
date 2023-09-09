#include <bits/stdc++.h>
using namespace std;

/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/

// Can also be done using level order traversal.

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
};

Node *connect(Node *root)
{
    if (!root)
        return root;
    if (root->left)
    {
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
    return root;
}

int main()
{

    return 0;
}