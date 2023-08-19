#include <bits/stdc++.h>
using namespace std;

/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at 
(N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at 
a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot 
move to any other cell.
*/

void fun(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans,
         string s, vector<vector<int>> &vis, int dr[], int dc[])
{
    if (i == n - 1 and j == n - 1)
    {
        ans.push_back(s);
        return;
    }
    string str = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nrow = i + dr[ind];
        int ncol = j + dc[ind];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and !vis[nrow][ncol] and m[nrow][ncol] == 1)
        {
            vis[i][j] = 1;
            fun(nrow, ncol, m, n, ans, s + str[ind], vis, dr, dc);
            vis[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    if (m[0][0])
        fun(0, 0, m, n, ans, "", vis, dr, dc);
    return ans;
}
int main()
{

    return 0;
}