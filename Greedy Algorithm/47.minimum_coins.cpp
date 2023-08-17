#include <bits/stdc++.h>
using namespace std;

/*
Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of C = {1, 2, 5, 10, 20, 50, 100, 500, 1000} 
valued coins, what is the minimum number of coins to make the change.
*/

vector<int> findMinimumCoins(int value)
{
    vector<int> denomination = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (value >= denomination[i])
        {
            value -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }
    return ans;
}

int main()
{

    return 0;
}