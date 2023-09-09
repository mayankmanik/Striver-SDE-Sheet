#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *helper(vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = (left + right) / 2;
    TreeNode *temp = new TreeNode(nums[mid]);
    temp->left = helper(nums, left, mid - 1);
    temp->right = helper(nums, mid + 1, right);
    return temp;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1);
}

int main()
{

    return 0;
}