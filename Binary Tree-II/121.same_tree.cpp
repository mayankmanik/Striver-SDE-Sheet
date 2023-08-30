#include <bits/stdc++.h>
using namespace std;

// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p or !q)
        return p == q;
    return ((p->val == q->val) and (isSameTree(p->left, q->left)) and (isSameTree(p->right, q->right)));
}

int main()
{

    return 0;
}