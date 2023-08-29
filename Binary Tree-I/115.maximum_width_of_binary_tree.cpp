#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return the maximum width of the given tree. The maximum width of a tree is the maximum
width among all levels. The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level
are also counted into the length calculation.
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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    long ans = 0;
    queue<pair<TreeNode *, long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        long mmin = q.front().second;
        long first, last;
        for (long i = 0; i < size; i++)
        {
            long cur_id = q.front().second - mmin;
            auto node = q.front().first;
            q.pop();
            if (i == 0)
                first = cur_id;
            if (i == size - 1)
                last = cur_id;
            if (node->left)
                q.push({node->left, cur_id * 2 + 1});
            if (node->right)
                q.push({node->right, cur_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{

    return 0;
}