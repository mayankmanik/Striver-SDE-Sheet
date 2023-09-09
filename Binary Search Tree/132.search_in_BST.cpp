#include <bits/stdc++.h>
using namespace std;

// You are given the root of a binary search tree (BST) and an integer val. If such a node does not exist, return null.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
        return NULL;
    while (root)
    {
        if (root->val == val)
            return root;
        else if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main()
{

    return 0;
}