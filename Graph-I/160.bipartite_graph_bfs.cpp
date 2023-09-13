#include <bits/stdc++.h>
using namespace std;


// bipartite graph- which can be colored using exactly 2 colors such that no two adjacent nodes have same color.

bool check_bfs(int i, vector<int> adj[], vector<int> &col)
{
    col[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        int node=q.front();
        q.pop();

        for (auto &it : adj[node])
        {
            if (col[it] == -1)
            {
                col[it] = 1 - col[node];
            }
            else if (col[it] == col[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<int> adj[], int n)
{
    vector<int> col(n, -1); // here col array will act as visited array.
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            if (check_bfs(i, adj, col) == false)
                return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}