#include <bits/stdc++.h>
using namespace std;

// Given an array nums with n objects colored 0, 1, or 2, sort them in-place.

void sortColors(vector<int> &nums)
{
    int a = 0, b = 0, c = nums.size() - 1;
    while (b <= c)
    {
        if (nums[b] == 2)
            swap(nums[b], nums[c--]);
        else if (nums[b] == 0)
            swap(nums[b++], nums[a++]);
        else
            b++;
    }
}

int main()
{

    return 0;
}