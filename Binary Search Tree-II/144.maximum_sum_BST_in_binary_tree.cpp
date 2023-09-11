#include <bits/stdc++.h>
using namespace std;

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Time Complexity - O(N)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node
{
public:
    bool bst;
    int maxi;
    int mini;
    int maxSum;
    Node()
    {
        bst = true;
        maxi = INT_MIN;
        mini = INT_MAX;
        maxSum = 0;
    }
};
class Solution
{
public:
    Node calcSum(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return Node();

        Node p;
        Node left = calcSum(root->left, ans);
        Node right = calcSum(root->right, ans);

        if (left.bst == true && right.bst == true && root->val > left.maxi && root->val < right.mini)
        {
            p.bst = true;
            p.maxSum = left.maxSum + right.maxSum + root->val;
            p.mini = min(root->val, left.mini);
            p.maxi = max(root->val, right.maxi);
        }
        else
        {
            p.bst = false;
            p.maxSum = max(left.maxSum, right.maxSum);
        }

        ans = max(ans, p.maxSum);
        return p;
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        calcSum(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}