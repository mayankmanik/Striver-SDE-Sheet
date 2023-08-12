#include <bits/stdc++.h>
using namespace std;


// Given an array of integers nums and an integer target, return indices of the two numbers such 
// that they add up to target.You may assume that each input would have exactly one solution, 
// and you may not use the same element twice. You can return the answer in any order.

// O(n)-Space Complexity and Time Complexity

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
            return {i, mp[target - nums[i]]};
        else
            mp[nums[i]] = i;
    }
    return ans;
}

int main()
{

    return 0;
}