#include <bits/stdc++.h>
using namespace std;

// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once.
// Return the single element that appears only once.

// Time Complexity- O(log(n))

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool isHalfEven = (mid - low) % 2 == 0;
        if (mid + 1 < n and nums[mid] == nums[mid + 1])
        {
            if (isHalfEven)
                low = mid + 2;
            else
                high = mid - 1;
        }
        else if (mid > 0 and nums[mid] == nums[mid - 1])
        {
            if (isHalfEven)
                high = mid - 2;
            else
                low = mid + 1;
        }
        else
            return nums[mid];
    }
    return -1;
}

int main()
{

    return 0;
}