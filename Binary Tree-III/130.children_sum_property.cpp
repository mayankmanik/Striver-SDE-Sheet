#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree of nodes'N, you need to modify the value of its nodes, such that the tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node
is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
2. You can not change the structure ot the original binary tree .
3. A binary tree is a tree in which each node has at most two children.
4. You can assume the value can be 6 for a NULL node and there can also be an empty tree.
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

void changeTree(TreeNode * root) {
    if (!root)
        return;
    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;

    if (root->val <= child)
        root->val = child;
    else
    {
        if (root->left)
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
        total += root->left->val;
    if (root->right)
        total += root->right->val;
    if (root->left or root->right)
        root->val = total;
}

int main()
{
    
    return 0;
}