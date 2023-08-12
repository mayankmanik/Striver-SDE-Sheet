#include <bits/stdc++.h>
using namespace std;

// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.

// O(log(mn)) - Time Complexity

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = (m * n) - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (matrix[mid / m][mid % m] == target)
            return true;
        else if (matrix[mid / m][mid % m] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{

    return 0;
}