#include <bits/stdc++.h>
using namespace std;

// You are given a BST with' N' number of nodes and a value X. Your task is to find the smallest value node of the BST which
// is greater than or equal to X.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findCeil(TreeNode *root, int X)
{
    int ans = -1;
    while (root)
    {
        if (root->val >= X)
        {
            ans = root->val;
            root = root->left;
        }
        else if (root->val < X)
            root = root->right;
    }
    return ans;
}

int main()
{

    return 0;
}