#include <bits/stdc++.h>
using namespace std;
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place.

// trnspose and reverse row wise

void rotate_image(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < row; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    return;
    for (int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{

    return 0;
}