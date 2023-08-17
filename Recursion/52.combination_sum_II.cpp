#include <bits/stdc++.h>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

void fun(vector<vector<int>> &ans, vector<int> candidates, vector<int> temp, int target, int ind)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind and candidates[i] == candidates[i - 1])
            continue;
        if (target >= candidates[i])
        {
            temp.push_back(candidates[i]);
            fun(ans, candidates, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
        else
        {
            break;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    sort(begin(candidates), end(candidates));
    vector<int> temp;
    fun(ans, candidates, temp, target, 0);
    return ans;
}

int main()
{

    return 0;
}