#include <bits/stdc++.h>
using namespace std;

bool topoSort(int n, vector<int> adj[])
{
    vector<int> indegree(n, 0);
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (auto &it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int cnt=0;
    while (!q.empty())
    {
        int node = q.front();
        cnt++;
        q.pop();

        for (auto &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return (cnt == n) ? false : true;
}

int main()
{

    return 0;
}