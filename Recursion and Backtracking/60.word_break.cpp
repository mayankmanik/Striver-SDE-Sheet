#include <bits/stdc++.h>
using namespace std;

// You are given a non-empty string S containing no spaces' and a dictionary of non-empty strings (say the
// list of words). You are supposed to construct and return all possible sentences after adding spaces in the
// originally given string 'S, such that each word in a sentence exists in the given dictionary.

void fun(int i, string s, string temp, vector<string> &ans, set<string> &dict)
{
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        if (dict.find(s.substr(i, j - i + 1)) != dict.end())
        {
            fun(j + 1, s, temp + s.substr(i, j - i + 1) + " ", ans, dict);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    set<string> dict(begin(dictionary), end(dictionary));
    fun(0, s, "", ans, dict);
    return ans;
}

int main()
{

    return 0;
}