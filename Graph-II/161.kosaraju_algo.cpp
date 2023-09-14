#include <bits/stdc++.h>
using namespace std;

// SCC is valid only for Directed graph
// This algo helps to find strongly connected component in directed graph
// if we take any two node in one component then we can go from u->v and from v->u

void dfs1(int i, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[i] = 1;
    for (auto &it : adj[i])
    {
        if (!vis[it])
            dfs1(it, st, vis, adj);
    }
    st.push(i);
}

void dfs3(int i, vector<int> &vis, vector<int> adjT[], vector<int> &temp)
{
    vis[i] = 1;
    temp.push_back(i);
    for (auto &it : adjT[i])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT, temp);
        }
    }
}

int kosaraju(vector<int> adj[], int n)
{
    /*
    1. sort all the edges a/c to finishing time
    2. reverse the graph
    3. perform dfs
    */
    vector<int> vis(n + 1, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs1(i, st, vis, adj);
    }

    vector<int> adjT[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    int count_scc = 0;
    vector<vector<int>> scc;
    vector<int> temp;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            count_scc++;
            dfs3(node, vis, adjT, temp);
            scc.push_back(temp);
        }
    }
    return count_scc;
}

int main()
{

    return 0;
}