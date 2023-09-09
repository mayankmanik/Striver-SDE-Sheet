#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool fun(TreeNode *root, long long min, long long max)
{
    if (!root)
        return true;
    if (root->val >= max or root->val <= min)
        return false;
    return fun(root->left, min, root->val) and fun(root->right, root->val, max);
}

bool isValidBST(TreeNode *root)
{
    return fun(root, LLONG_MIN, LLONG_MAX);
}

int main()
{

    return 0;
}