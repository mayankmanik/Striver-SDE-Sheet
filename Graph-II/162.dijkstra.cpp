#include <bits/stdc++.h>
using namespace std;

// single source shortest path algo
// this algo doesn't works for negative edge and negative weight cycle
// Time Complexity- Elog(V)

vector<int> dijkstra_algo_using_set(int n, vector<pair<int, int>> adj[], int src)
{ // dist,node
    set<pair<int, int>> st;
    vector<int> dist(n, 1e9);
    st.insert({0, src});
    dist[src] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto &i : adj[node])
        {
            int nextNode = i.first;
            int edgeWeight = i.second;

            if (dist[nextNode] > dis + edgeWeight)
            {
                if (dis + edgeWeight != 1e9)
                {
                    st.erase({dist[nextNode], nextNode});
                }
                dist[nextNode] = dis + edgeWeight;
                st.insert({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}

vector<int> dijkstra_algo_using_priority_queue(int n, vector<pair<int, int>> adj[], int src)
{ // dist,node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &it : adj[node])
        {
            int nextNode = it.first;
            int edgeWeight = it.second;
            if (dist[nextNode] > dist[node] + edgeWeight)
            {
                dist[nextNode] = dist[node] + edgeWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}