#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[])
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

    while (!q.empty())
    {
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for (auto &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}
int main()
{

    return 0;
}