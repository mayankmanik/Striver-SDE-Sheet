#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, flatten the tree into a "linked list":
1. The "linked list" should use the same TreeNode class where the right child points to the next node in the list and the left child is always null.
2. The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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

// Time Complexity - O(n)
// Space Complexity - O(n)

void helper(TreeNode *root, TreeNode *&prev)
{
    if (!root)
        return;
    helper(root->right, prev);
    helper(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flatten(TreeNode *root)
{
    TreeNode *prev = NULL;
    helper(root, prev);
}

// Time Complexity - O(n)
// Space Complexity - O(1)

TreeNode *flattenTree(TreeNode *root)
{
    if (!root)
        return root;
    TreeNode *curr = root;
    TreeNode *prev = NULL;
    while (curr)
    {
        if (curr->left)
        {
            prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
    return root;
}

int main()
{

    return 0;
}