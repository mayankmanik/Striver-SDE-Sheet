#include <bits/stdc++.h>
using namespace std;

// Given a string s, find the length of the longest substring without repeating characters.

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;
    int i = 0, j = 0;
    int ans = INT_MIN;
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}
int main()
{

    return 0;
}