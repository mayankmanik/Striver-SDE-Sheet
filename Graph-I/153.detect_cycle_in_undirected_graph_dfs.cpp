#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int i,int parent,int n,vector<int> adj[],vector<int> &vis)
{
    vis[i]=1;
    for (auto &it : adj[i])
    {
        if(!vis[it])
        {
            if(dfsCycle(it,i,n,adj,vis))
                return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
    
}

bool isCycle(int n,vector<int> adj[])
{
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfsCycle(i,-1,n,adj,vis))
                return true;
        }
    }
    return false;
}

int main()
{
    
    return 0;
}