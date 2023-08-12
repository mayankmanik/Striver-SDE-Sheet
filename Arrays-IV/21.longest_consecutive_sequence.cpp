#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// O(n)-Time Complexity

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto it : nums)
        mp[it] = 1;
    for (auto it : mp)
    {
        if (mp.find(it.first - 1) != mp.end())
            mp[it.first] = 0;
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[nums[i]] == 1)
        {
            int len = 1;
            while (mp.find(nums[i] + len) != mp.end())
                len++;
            ans = max(ans, len);
        }
    }
    return ans;
}

int main()
{

    return 0;
}