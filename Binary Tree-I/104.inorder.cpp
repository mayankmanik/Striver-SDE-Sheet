#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the inorder traversal of its TreeNodes' values.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive

void inorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// Iterative

void inorderIterative(TreeNode *root, vector<int> &ans)
{
    stack<TreeNode *> st;
    TreeNode *TreeNode = root;
    while (true)
    {
        if (TreeNode)
        {
            st.push(TreeNode);
            TreeNode = TreeNode->left;
        }
        else
        {
            if (st.empty())
                break;
            TreeNode = st.top();
            st.pop();
            ans.push_back(TreeNode->val);
            TreeNode = TreeNode->right;
        }
    }
}

int main()
{
    
    return 0;
}