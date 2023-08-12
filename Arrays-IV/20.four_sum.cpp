#include <bits/stdc++.h>
using namespace std;

// Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// O(n^3)- Time Complexity

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(begin(nums), end(nums));
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long target2 = 1ll * target - nums[i] - nums[j];
            int left = j + 1, right = n - 1;

            while (left < right)
            {
                int two_sum = nums[left] + nums[right];
                if (two_sum > target2)
                    right--;
                else if (two_sum < target2)
                    left++;
                else
                {
                    vector<int> q(4, 0);
                    q[0] = nums[i];
                    q[1] = nums[j];
                    q[2] = nums[left];
                    q[3] = nums[right];
                    ans.push_back(q);

                    while (left < right and nums[left] == q[2])
                        left++;
                    while (left < right and nums[right] == q[3])
                        right--;
                }
            }
            while (j + 1 < n and nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < n and nums[i + 1] == nums[i])
            i++;
    }
    return ans;
}

int main()
{

    return 0;
}