#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.

// Time Complexity - O(N)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int fun(TreeNode *root, int &dia)
{
    if (!root)
        return 0;
    int lh = fun(root->left, dia);
    int rh = fun(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int dia = 0;
    fun(root, dia);
    return dia;
}

int main()
{

    return 0;
}