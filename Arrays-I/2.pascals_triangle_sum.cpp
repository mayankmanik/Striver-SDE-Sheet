#include <bits/stdc++.h>
using namespace std;

// Given an integer numRows, return the first numRows of Pascal's triangle.

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back({1});
    for (int i = 1; i < numRows; i++)
    {
        auto vec = ans[i - 1];
        vector<int> temp;
        for (int j = 0; j <= vec.size(); j++)
        {
            if (j == 0 or j == vec.size())
                temp.push_back(1);
            else
                temp.push_back(vec[j - 1] + vec[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}