#include <bits/stdc++.h>
using namespace std;

// KADANE's Algorithm
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

int maxSubArray(vector<int> &nums)
{
    int maxsum = nums[0];
    int currsum = 0;
    for (auto &i : nums)
    {
        currsum += i;
        maxsum = max(maxsum, currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}

int main()
{

    return 0;
}