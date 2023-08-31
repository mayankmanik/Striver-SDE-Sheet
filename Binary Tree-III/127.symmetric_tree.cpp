#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool fun(TreeNode *p, TreeNode *q)
{
    if (!p or !q)
        return p == q;
    return (p->val == q->val) and fun(p->left, q->right) and fun(p->right, q->left);
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return fun(root->left, root->right);
}

int main()
{

    return 0;
}