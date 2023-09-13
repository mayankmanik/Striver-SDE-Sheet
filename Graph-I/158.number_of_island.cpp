#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

void fun(vector<vector<char>> grid, int i, int j, vector<vector<int>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;
        for (int i = 0; i < 4; i++)
        {
            int nrow = x + drow[i];
            int ncol = y + dcol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == '1')
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and grid[i][j] == '1')
            {
                ans++;
                fun(grid, i, j, vis);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}