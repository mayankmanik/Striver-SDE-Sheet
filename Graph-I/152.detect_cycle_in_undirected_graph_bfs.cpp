#include <bits/stdc++.h>
using namespace std;

bool bfsCycle(int i,int n,vector<int> adj[],vector<int> &vis)
{
    vis[i]=1;
            // node ,parent
    queue<pair<int,int>> q;
    q.push({i,-1});
    while (!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for (auto &it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if(it!=parent)
            {
                return true;
            }
        }
    }
    return false;
    
}

bool isCycle(int n,vector<int> adj[])
{
    vector<int> vis(n,0);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            if(bfsCycle(i,n,adj,vis))
                return true;
        }
    }
    return false;    
}

int main()
{
    
    return 0;
}