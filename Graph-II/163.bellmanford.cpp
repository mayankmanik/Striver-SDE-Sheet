#include <bits/stdc++.h>
using namespace std;

// single source shortest path algo
// this algo works for directed graph. for undirected graph we have to convert that into directed graph.
// this algo works for negative edge and helps to detect negative weight cycle.
// // Time Complexity- E*V

vector<int> bellman_ford(vector<vector<int>> edges, int n, int src)
{
    vector<int> dis(n, 1e8);
    dis[src] = 0;
    // Since in a graph of N nodes, in worst case, you will
    // take N-1 edges to reach from the first to the last,
    // thereby we iterate for N-1 iterations.
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dis[u] != 1e8 and dis[u] + wt < dis[v])
            {
                dis[v] = wt + dis[u];
            }
        }
    }

    // for checking negative weight cycle in graph
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dis[u] != 1e8 and dis[u] + wt < dis[v])
        {
            return {-1};
        }
    }

    return dis;
}
int main()
{

    return 0;
}