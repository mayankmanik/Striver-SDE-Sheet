#include <bits/stdc++.h>
using namespace std;

// Spanning Tree - N nodes, N-1 edges, each node can be reached by every other node
// This algo is used to find minimum spanning tree and its weight.

int prims(vector<vector<int>> adj[], int n)
{
    // weight,node,parent
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(n, 0);
    pq.push({0, {0, -1}});
    int sum = 0;
    vector<pair<int,int>> mst;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int par = it.second.second;
        if (vis[node] == 1)
            continue;
        if(par!=-1)
            mst.push_back({node,par});
        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (!vis[adjNode])
                pq.push({edgeWt, {adjNode, node}});
        }
    }
    return sum;
}
int main()
{

    return 0;
}