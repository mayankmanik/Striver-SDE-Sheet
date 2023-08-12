#include <bits/stdc++.h>
using namespace std;

// Given an array of integers arr and an integer x you are supposed to find the number of subarrays of arr 
// which have bitwise xor of the-elements equal to x.

// O(nloog(n)) - Time Complexity

int subarraysXor(vector<int> &arr, int x)
{
    map<int, int> mp;
    int xorr = 0, cnt = 0;
    for (auto it : arr)
    {
        xorr ^= it;
        if (xorr == x)
            cnt++;
        if (mp.find(x ^ xorr) != mp.end())
            cnt += mp[x ^ xorr];
        mp[xorr]++;
    }
    return cnt;
}

int main()
{

    return 0;
}