#include <bits/stdc++.h>
using namespace std;

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very 
// left of the array to the very right. You can only see the k numbers in the window. Each time the 
// sliding window moves right by one position. Return the max sliding window.

// Time Complexity - O(N)
// Space Complexity - O(N)

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;      // tried maintaining decreasing order in deque
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() and dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() and nums[i] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main()
{

    return 0;
}