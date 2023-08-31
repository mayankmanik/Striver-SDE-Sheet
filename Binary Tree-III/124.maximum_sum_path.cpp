#include <bits/stdc++.h>
using namespace std;

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int fun(TreeNode *root, int &maxi)
{
    if (!root)
        return 0;
    int lsum = max(0, fun(root->left, maxi));
    int rsum = max(0, fun(root->right, maxi));
    maxi = max(maxi, lsum + rsum + root->val);
    return root->val + max(lsum, rsum);
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    fun(root, maxi);
    return maxi;
}

int main()
{

    return 0;
}