#include <bits/stdc++.h>
using namespace std;

// Given a directed graph. The task is to do Depth First Traversal of this graph starting from 0.

void dfs(vector<int> adj[], int i, vector<int> &vis, vector<int> &vec)
{
    vis[i] = 1;
    vec.push_back(i);
    for (auto it : adj[i])
    {
        if (!vis[it])
            dfs(adj, it, vis, vec);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vec;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(adj, i, vis, vec);
    }
    return vec;
}

int main()
{

    return 0;
}