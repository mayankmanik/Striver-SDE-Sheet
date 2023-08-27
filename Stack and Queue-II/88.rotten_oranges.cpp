#include <bits/stdc++.h>
using namespace std;

// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
// If this is impossible, return -1.

void fun(queue<pair<pair<int, int>, int>> q, vector<vector<int>> &grid, vector<vector<int>> &vis, int &ans)
{
    int n = grid.size(), m = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int row = it.first.first;
        int col = it.first.second;
        int timer = it.second;
        ans = max(ans, timer);
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, timer + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }
}
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    fun(q, grid, vis, ans);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 and !vis[i][j])
                return -1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}