#include <bits/stdc++.h>
using namespace std;

// Given an integer array. The task is to find the maximum of the minimum of every window size in the array.

// Time Complexity - O(N)
// Space Complexity - O(N)

vector<int> maxMinWindow(vector<int> arr, int n)
{
    stack<int> s;

    int left[n + 1];
    int right[n + 1];

    for (int i = 0; i < n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            left[i] = s.top();

        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            right[i] = s.top();

        s.push(i);
    }

    vector<int> ans(n + 1, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }
    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    return {ans.begin() + 1, ans.end()};
}

int main()
{

    return 0;
}