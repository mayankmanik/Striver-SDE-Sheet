#include <bits/stdc++.h>
using namespace std;

// You are given an array consisting of n integers which denote the position of a stall.
// You are also given an integer k which denotes the number of aggressive cows. You are given the task of
// assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

// Time Complexity - O(NLog(N))

bool canPlace(vector<int> stalls, int mid, int k)
{
    int cnt = 1, cord = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - cord >= mid)
        {
            cord = stalls[i];
            cnt++;
        }
        if (cnt == k)
            return true;
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{
    sort(begin(stalls), end(stalls));
    int res = 0;
    int low = 1, high = stalls[n - 1] - low;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, mid, k))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

int main()
{

    return 0;
}