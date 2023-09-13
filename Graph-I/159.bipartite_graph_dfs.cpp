#include <bits/stdc++.h>
using namespace std;

bool check_dfs(int i,int startColor,vector<int> &col,vector<int> adj[])
{
    col[i]=startColor;
    
    for (auto &it : adj[i])
    {
        if(col[it]==-1)
        {
            if(check_dfs(it,1-startColor,col,adj)==false)    return false;
        }
        else if(col[it]==startColor)
            return false;
    }
    return true;   
}

bool isBipartite(vector<int> adj[],int n)
{
    vector<int> col(n,-1);
    for(int i=0;i<n;i++)
    {
        if(col[i]==-1)
        {
            if(check_dfs(i,0,col,adj)==false)   return false;
        }
    }
    return true;
}
int main()
{
    
    return 0;
}