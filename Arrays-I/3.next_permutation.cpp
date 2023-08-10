#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums, find the next permutation of nums.

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
            break;
    }
    if (k < 0)
        reverse(begin(nums), end(nums));
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
                break;
        }
        swap(nums[k], nums[l]);
        reverse(begin(nums) + k + 1, end(nums));
    }
}

int main()
{

    return 0;
}