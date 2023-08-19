#include <bits/stdc++.h>
using namespace std;

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

void fun(vector<vector<int>> &ans, vector<int> nums, int i, int n)
{
    if (i == n)
    {
        ans.push_back(nums);
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(nums[j], nums[i]);
        fun(ans, nums, i + 1, n);
        ;
        swap(nums[j], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    fun(ans, nums, 0, nums.size());
    return ans;
}

int main()
{

    return 0;
}