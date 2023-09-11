#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void fun(TreeNode *root, int &k, int &ans)
{
    if (!root)
        return;
    fun(root->left, k, ans);
    if (--k == 0)
        ans = root->val;
    fun(root->right, k, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = -1;
    fun(root, k, ans);
    return ans;
}
int main()
{

    return 0;
}