#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums that may contain duplicates, return all possible 
// subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

void fun(vector<int> nums, vector<vector<int>> &ans, vector<int> temp, int ind)
{
    ans.push_back(temp);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i == ind or nums[i] != nums[i - 1])
        {
            temp.push_back(nums[i]);
            fun(nums, ans, temp, i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(begin(nums), end(nums));
    fun(nums, ans, temp, 0);
    return ans;
}

int main()
{

    return 0;
}