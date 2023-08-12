#include <bits/stdc++.h>
using namespace std;

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.


int fun(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = fun(i, j - 1, dp);
    int up = fun(i - 1, j, dp);
    return dp[i][j] = left + up;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun(m - 1, n - 1, dp);
}

int main()
{

    return 0;
}