#include <bits/stdc++.h>
using namespace std;

// Given below is a binary tree. The task is to print the top view of binary tree.

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> topView(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    map<int, int> mp;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front().first;
            int level = q.front().second;
            if (mp.find(level) == mp.end())
                mp[level] = node->data;
            q.pop();
            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
    }
    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}

int main()
{

    return 0;
}