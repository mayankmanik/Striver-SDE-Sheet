#include <bits/stdc++.h>
using namespace std;

// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

bool isPalindrome(int j, string s, int i)
{
    while (i <= j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
void fun(vector<vector<string>> &ans, vector<string> temp, string s, int ind)
{
    if (ind == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(i, s, ind))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            fun(ans, temp, s, i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    fun(ans, temp, s, 0);
    return ans;
}

int main()
{

    return 0;
}