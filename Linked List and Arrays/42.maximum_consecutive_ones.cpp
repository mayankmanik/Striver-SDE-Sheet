#include <bits/stdc++.h>
using namespace std;

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ans = 0, maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            ans++;
        }
        else
        {
            maxi = max(maxi, ans);
            ans = 0;
        }
    }
    return maxi = max(maxi, ans);
}
int main()
{

    return 0;
}