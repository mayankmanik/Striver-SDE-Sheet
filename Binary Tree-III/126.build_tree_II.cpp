#include <bits/stdc++.h>
using namespace std;

// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a
// binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *fun(int is, int ie, vector<int> &in, int ps, int pe, vector<int> &po, unordered_map<int, int> &mp)
{
    if (is > ie or ps > pe)
        return NULL;
    TreeNode *root = new TreeNode(po[pe]);
    int inroot = mp[root->val];
    int numsleft = inroot - is;

    root->left = fun(is, inroot - 1, in, ps, ps + numsleft - 1, po, mp);
    root->right = fun(inroot + 1, ie, in, ps + numsleft, pe - 1, po, mp);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return fun(0, inorder.size() - 1, inorder, 0, postorder.size() - 1, postorder, mp);
}

int main()
{

    return 0;
}