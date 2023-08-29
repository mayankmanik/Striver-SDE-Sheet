#include <bits/stdc++.h>
using namespace std;

// Given a Binary Tree of size N, you need to find the path from root to node of the binary tree.

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool fun(Node *root, vector<int> &ans, int val)
{
    if (!root)
        return false;
    ans.push_back(root->data);
    if (root->data == val)
        return true;
    if (fun(root->left, ans, val) or fun(root->right, ans, val))
        return true;

    ans.pop_back();
    return false;
}

vector<int> rootToNodePath(Node *root, int val)
{
    vector<int> ans;
    if (!root)
        return ans;
    fun(root, ans, val);
    return ans;
}

int main()
{

    return 0;
}