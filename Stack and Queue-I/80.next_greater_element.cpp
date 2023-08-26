#include <bits/stdc++.h>
using namespace std;

// Given a circular integer array nums
// (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number 
// for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array,
// which means you could search circularly to find its next greater number. 
// If it doesn't exist, return -1 for this number.

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top() <= nums[i % n])
            st.pop();
        if (i < n)
        {
            if (!st.empty())
                ans[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return ans;
}

int main()
{

    return 0;
}