#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the preorder traversal of its TreeNodes' values.


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

void preorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// Iterative

void preorderIterative(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        ans.push_back(node->val);

        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
}

int main()
{

    return 0;
}