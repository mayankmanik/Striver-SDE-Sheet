#include <bits/stdc++.h>
using namespace std;

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
// return the area of the largest rectangle in the histogram.

void nextSmallerElement(vector<int> &nse, vector<int> &h, int n)
{
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and h[st.top()] >= h[i])
            st.pop();
        if (st.empty())
            nse[i] = n;
        else
            nse[i] = st.top();
        st.push(i);
    }
}
void previousSmallerElement(vector<int> &pse, vector<int> &h, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and h[st.top()] >= h[i])
            st.pop();
        if (st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top();
        st.push(i);
    }
}
int largestRectangleArea(vector<int> &h)
{
    int ans = 0;
    int n = h.size();
    vector<int> nse(n, 0);
    vector<int> pse(n, 0);
    nextSmallerElement(nse, h, n);
    previousSmallerElement(pse, h, n);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, h[i] * (nse[i] - pse[i] - 1));
    }
    return ans;
}

int main()
{
    return 0;
}