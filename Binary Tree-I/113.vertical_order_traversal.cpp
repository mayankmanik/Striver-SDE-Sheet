#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
*/

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    // node,vertical,level
    queue<pair<TreeNode *, pair<int, int>>> q;
    // vertical,level,data
    map<int, map<int, multiset<int>>> ms;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto vertical = it.second.first;
        auto level = it.second.second;
        ms[vertical][level].insert(node->val);
        if (node->left)
            q.push({node->left, {vertical - 1, level + 1}});
        if (node->right)
            q.push({node->right, {vertical + 1, level + 1}});
    }

    for (auto it : ms)
    {
        vector<int> temp;
        for (auto jt : it.second)
        {
            temp.insert(temp.end(), jt.second.begin(), jt.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}