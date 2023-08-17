#include <bits/stdc++.h>
using namespace std;


// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

void fun(vector<int> candidates, vector<vector<int>> &ans, vector<int> temp, int target, int i)
{
    if (i == candidates.size())
    {
        if (target == 0)
            ans.push_back(temp);
        return;
    }
    if (candidates[i] <= target)
    {
        temp.push_back(candidates[i]);
        fun(candidates, ans, temp, target - candidates[i], i);
        temp.pop_back();
    }
    fun(candidates, ans, temp, target, i + 1);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    fun(candidates, ans, temp, target, 0);
    return ans;
}
int main()
{

    return 0;
}