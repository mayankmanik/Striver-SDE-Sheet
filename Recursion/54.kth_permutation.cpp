#include <bits/stdc++.h>
using namespace std;

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// Given n and k, return the kth permutation sequence.

string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans = "";
    k--;
    while (true)
    {
        ans = ans + to_string(num[k / fact]);
        num.erase(begin(num) + k / fact);
        if (num.size() == 0)
            break;
        k = k % fact;
        fact /= num.size();
    }
    return ans;
}

int main()
{

    return 0;
}