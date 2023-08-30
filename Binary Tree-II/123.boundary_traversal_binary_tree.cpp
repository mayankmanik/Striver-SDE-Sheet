#include <bits/stdc++.h>
using namespace std;

// You have been given a binary tree of integers. Your task is to print the boundary nodes of this binary tree in
// Anti-Clockwise direction starting from the root node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *root)
{
    return (!root->left and !root->right);
}

void preorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!isLeaf(root))
        ans.push_back(root->val);
    preorder(root->left, ans);
    if (!root->left)
        preorder(root->right, ans);
}

void inorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    if (isLeaf(root))
        ans.push_back(root->val);
    inorder(root->right, ans);
}

void reversePostorder(TreeNode *root, stack<int> &st)
{
    if (!root)
        return;
    if (!isLeaf(root))
        st.push(root->val);
    reversePostorder(root->right, st);
    if (!root->right)
        reversePostorder(root->left, st);
}

vector<int> traverseBoundary(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->val);
    stack<int> st;

    preorder(root->left, ans);
    inorder(root, ans);
    reversePostorder(root->right, st);

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{

    return 0;
}