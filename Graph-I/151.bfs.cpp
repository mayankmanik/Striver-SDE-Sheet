#include <bits/stdc++.h>
using namespace std;

// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

void bfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &vec)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        vec.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> vec;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            bfs(i, adj, vis, vec);
    }
    return vec;
}

int main()
{

    return 0;
}