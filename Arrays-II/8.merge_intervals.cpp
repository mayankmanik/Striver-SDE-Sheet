#include <bits/stdc++.h>
using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

bool doesIntervalsOverlap(vector<int> &a, vector<int> &b)
{
    return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
}

vector<int> mergeIntervals(vector<int> &a, vector<int> &b)
{
    return {min(a[0], b[0]), max(a[1], b[1])};
}

vector<vector<int>> merge(vector<vector<int>> &inv)
{
    int n = inv.size();
    vector<vector<int>> v;
    int i = 0;
    sort(inv.begin(), inv.end());
    while (i < n)
    {
        vector<int> merge = inv[i++];
        while (i < n and doesIntervalsOverlap(merge, inv[i]))
        {
            merge = mergeIntervals(merge, inv[i]);
            i++;
        }
        v.push_back(merge);
    }
    return v;
}
int main()
{

    return 0;
}