#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void fun(TreeNode *root, vector<int> &v)
{
    if (!root)
        return;
    fun(root->left, v);
    v.push_back(root->val);
    fun(root->right, v);
}

bool findTarget(TreeNode *root, int k)
{
    vector<int> v;
    fun(root, v);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == k)
            return true;
        else if (v[i] + v[j] > k)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{

    return 0;
}