#include <bits/stdc++.h>
using namespace std;

// You have been given K' different arrays/lists, which are sorted individually (in
// ascending order). You need to merge all the given /arrays/list such that the output
// array/list should be sorted in ascending order.

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({kArrays[i][0], {0, i}});
    }
    while (!pq.empty())
    {
        auto it = pq.top();
        int val = it.first;
        int ind = it.second.first;
        int row = it.second.second;
        pq.pop();
        ans.push_back(val);
        if (ind + 1 < kArrays[row].size())
        {
            pq.push({kArrays[row][ind + 1], {ind + 1, row}});
        }
    }
    return ans;
}

int main()
{

    return 0;
}