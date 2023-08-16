#include <bits/stdc++.h>
using namespace std;

// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

// O(1)-Space Complexity

int trap(vector<int> &height)
{
    int ans = 0;
    int leftMax = 0, rightMax = 0;
    int i = 0, j = height.size() - 1;
    while (i < j)
    {
        if (height[i] <= height[j])
        {
            if (height[i] >= leftMax)
                leftMax = height[i];
            else
                ans += leftMax - height[i];
            i++;
        }
        else
        {
            if (height[j] >= rightMax)
                rightMax = height[j];
            else
                ans += rightMax - height[j];
            j--;
        }
    }
    return ans;
}

int main()
{

    return 0;
}