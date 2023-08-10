#include <bits/stdc++.h>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// NOTE
/*
    O(m+n) sol: use two additional array for storing row and col no. of zeroes in matrix.
    given below is O(1) in terms of space.
*/
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool col = true;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            col = false;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 or matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (col == 0)
            matrix[i][0] = 0;
    }
}

int main()
{

    return 0;
}