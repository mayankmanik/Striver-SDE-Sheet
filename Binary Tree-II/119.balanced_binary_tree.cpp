#include <bits/stdc++.h>
using namespace std;

// Given a binary tree, determine if it is height-balanced.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int fun(TreeNode *root)
{
    if (!root)
        return 0;
    int lh = fun(root->left);
    if (lh == -1)
        return -1;
    int rh = fun(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root)
{
    return fun(root) != -1;
}

int main()
{

    return 0;
}