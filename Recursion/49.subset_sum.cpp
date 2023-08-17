#include <bits/stdc++.h>
using namespace std;

// Given a list arr of N integers, print sums of all subsets in it.

void fun(vector<int> arr, vector<int> &ans, int i, int sum)
{
    if (i == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    fun(arr, ans, i + 1, sum + arr[i]);
    fun(arr, ans, i + 1, sum);
    return;
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    fun(arr, ans, 0, 0);
    return ans;
}
int main()
{

    return 0;
}