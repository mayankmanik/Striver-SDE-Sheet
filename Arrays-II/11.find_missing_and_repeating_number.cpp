#include <bits/stdc++.h>
using namespace std;

// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which is missing and B which appears twice. Return A and B.

// O(1)-space complexity

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int xorr = 0;
    for (int i = 1; i <= n; i++)
        xorr ^= arr[i - 1], xorr ^= i;
    int notFound = 0, found = 0;
    int setBit = xorr & (~(xorr - 1));  //finding last setBit
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setBit)
            found ^= arr[i];
        else
            notFound ^= arr[i];
        if ((i + 1) & setBit)
            found ^= (i + 1);
        else
            notFound ^= (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == found)
            break;
        if (arr[i] == notFound)
            swap(found, notFound);
    }
    return {notFound, found};
}

int main()
{

    return 0;
}