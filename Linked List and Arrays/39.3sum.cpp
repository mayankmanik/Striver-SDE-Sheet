#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.


vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(begin(nums), end(nums));
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums[i] > 0)
            return ans;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int low = i + 1, high = nums.size() - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] + nums[i] == 0)
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                int lo = nums[low], hi = nums[high];
                while (low < high and lo == nums[low])
                    low++;
                while (low < high and hi == nums[high])
                    high--;
            }
            else if (nums[i] + nums[low] + nums[high] > 0)
                high--;
            else
                low++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}