#include <bits/stdc++.h>
using namespace std;

// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element 
// without doing any modification in Binary Search Tree.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void count(TreeNode  *root, int &N)
{
    if (!root)
        return;
    count(root->left, N);
    N++;
    count(root->right, N);
}

void fun(TreeNode  *root, int &ans, int &k)
{
    if (!root)
        return;
    fun(root->left, ans, k);
    if (--k == 0)
        ans = root->val;
    fun(root->right, ans, k);
}

int kthLargest(TreeNode  *root, int K)
{
    int ans = -1;
    int N = 0;
    count(root, N);
    N -= K - 1;
    fun(root, ans, N);
    return ans;
}

int main()
{

    return 0;
}