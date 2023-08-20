#include <bits/stdc++.h>
using namespace std;

// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

int median(vector<vector<int>> &matrix, int R, int C)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < R; i++)
    {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][C - 1]);
    }

    int desired = (R * C + 1) / 2;  // index of median if all elements are put in 1D array

    while (mini < maxi)
    {
        int mid = (mini + maxi) / 2;
        int curr_count = 0;
        for (int i = 0; i < R; i++)
        {
            int l = 0;
            int r = C - 1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (matrix[i][m] <= mid)
                    l = m + 1;
                else
                    r = m - 1;
            }
            curr_count += l;
        }
        if (curr_count < desired)
            mini = mid + 1;
        else
            maxi = mid;
    }
    return mini;
}

int main()
{

    return 0;
}