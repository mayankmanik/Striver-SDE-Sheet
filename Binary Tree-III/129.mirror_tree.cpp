#include <bits/stdc++.h>
using namespace std;

// Given a Binary Tree, convert it into its mirror.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void mirror(TreeNode *node)
{
    if (!node)
        return;
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}

int main()
{

    return 0;
}