#include <bits/stdc++.h>
using namespace std;

// It is valid only for DAG. If there is an edge between u and v then in topo sort u must appear before v
 
void findTopo_dfs(int i, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[i] = 1;
    for (auto &it : adj[i])
    {
        if (!vis[it])
        {
            findTopo_dfs(it, vis, adj, st);
        }
    }
    st.push(i);
}
vector<int> topoSort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            findTopo_dfs(i, vis, adj, st);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
int main()
{

    return 0;
}