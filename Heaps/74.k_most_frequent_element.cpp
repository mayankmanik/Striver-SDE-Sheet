#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> mp;
    for (auto it : nums)
        mp[it]++;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push({it->second, it->first});
        if (pq.size() > k)
            pq.pop();
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main()
{

    return 0;
}