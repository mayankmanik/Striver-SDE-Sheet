#include <bits/stdc++.h>
using namespace std;

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root)
    {
        if (p->val > root->val and q->val > root->val)
            root = root->right;
        else if (p->val < root->val and q->val < root->val)
            root = root->left;
        else
            return root;
    }
    return root;
}

int main()
{

    return 0;
}