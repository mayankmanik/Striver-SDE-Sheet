#include <bits/stdc++.h>
using namespace std;

bool check_dfs(int i,vector<int> &vis,vector<int> &pathVis,vector<int> adj[])
{
    vis[i]=1;
    pathVis[i]=1;

    for (auto &it : adj[i])
    {
        if(!vis[i])
        {
            if(check_dfs(it,vis,pathVis,adj))
                return true;
        }
        else if(pathVis[it])
            return true;
    }
    pathVis[i]=0;
    return false;    
}

bool isCycle(int n,vector<int> adj[])
{
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            if(check_dfs(i,vis,pathVis,adj))
                return true;
        }
    }
    return false;
    
}

int main()
{
    
    return 0;
}