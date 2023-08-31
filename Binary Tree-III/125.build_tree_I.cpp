#include <bits/stdc++.h>
using namespace std;

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is
// the inorder traversal of the same tree, construct and return the binary tree.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *fun(int is, int ie, vector<int> &inorder, int ps, int pe, vector<int> &preorder, unordered_map<int, int> &mp)
{
    if (ps > pe or is > ie)
        return NULL;
    TreeNode *root = new TreeNode(preorder[ps]);

    int ind = mp[root->val];
    int numsLeft = ind - is;

    root->left = fun(is, ind - 1, inorder, ps + 1, ps + numsLeft, preorder, mp);
    root->right = fun(ind + 1, ie, inorder, ps + numsLeft + 1, pe, preorder, mp);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return fun(0, inorder.size() - 1, inorder, 0, preorder.size() - 1, preorder, mp);
}

int main()
{

    return 0;
}