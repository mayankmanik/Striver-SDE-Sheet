#include <bits/stdc++.h>
using namespace std;

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

// If the majority element is not necessarily present, then we have to manually check.
// O(1)-Space Complexity

int majorityElement(vector<int> &nums)
{
    int candidate = nums[0], cnt = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != candidate)
            cnt--;
        else
            cnt++;
        if (cnt == 0)
            candidate = nums[i], cnt = 1;
    }
    return candidate;
}

int main()
{

    return 0;
}