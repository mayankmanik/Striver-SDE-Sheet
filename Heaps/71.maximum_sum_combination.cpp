#include <bits/stdc++.h>
using namespace std;

// You are given two arrays/lists A and 'B' of size 'N' each. You are also given an integer
// K. You have to find the 'K' maximum and valid sum combinations from all the
// possible sum combinations of the arrays/lists 'A' and 'B.
// Sum combination is made by adding one element from array 'A' and another element from array 'B'

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(begin(a), end(a), greater<int>());
    sort(begin(b), end(b), greater<int>());

    set<pair<int, int>> st;
    st.insert({0, 0});
    pq.push({a[0] + b[0], {0, 0}});
    while (k--)
    {
        int val = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        ans.push_back(val);

        if (j + 1 < n and st.find({i, j + 1}) == st.end())
        {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
            st.insert({i, j + 1});
        }
        if (i + 1 < n and st.find({i + 1, j}) == st.end())
        {
            pq.push({a[i + 1] + b[j], {i + 1, j}});
            st.insert({i + 1, j});
        }
    }
    return ans;
}

int main()
{

    return 0;
}