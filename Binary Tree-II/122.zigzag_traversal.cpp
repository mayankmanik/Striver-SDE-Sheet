#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
// (i.e., from left to right, then right to left for the next level and alternate between).

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool reverse = false;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v(sz);
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            int ind = reverse ? sz - i - 1 : i;
            v[ind] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        reverse = !reverse;
        ans.push_back(v);
    }
    return ans;
}

int main()
{

    return 0;
}