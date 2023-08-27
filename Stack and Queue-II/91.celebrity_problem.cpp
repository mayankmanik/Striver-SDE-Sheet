#include <bits/stdc++.h>
using namespace std;

// A celebrity is a person who is known to all but does not know anyone at a party. 
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element 
// of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

// Time Complexity - O(n)

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b])
        {
            st.push(b);
        }
        else if (M[b][a])
        {
            st.push(a);
        }
    }
    if (st.empty())
        return -1;
    int x = st.top();
    for (int i = 0; i < n; i++)
    {
        if (M[i][x] == 0 and i != x)
        {
            return -1;
        }
        if (M[x][i] == 1 and i != x)
        {
            return -1;
        }
    }
    return x;
}

int main()
{

    return 0;
}