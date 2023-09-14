#include <bits/stdc++.h>
using namespace std;

// Multi source shortest path algo
// detects megative cycle
// Time Complexity- N*N*N

void floyd_warshal_algo(vector<vector<int>> mat)
{
    // mat cosists weighted graph
    int n = mat.size();

    for (int k = 0; k < n; k++) // via node
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][i] < 0)
        {
            cout << "There is negative weight cycle";
        }
    }
}
int main()
{

    return 0;
}