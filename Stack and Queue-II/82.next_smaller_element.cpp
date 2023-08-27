#include <bits/stdc++.h>
using namespace std;

// You are given an array ARR of integers of length N. YOur task is to ind the next smaller element for each 
// of the array elements.Next Smaller Element for an array element is the first element to the right of that
// element which has a value strictly smaller than that element.
// If for any array element the next smaller element does not exist, you should print -1 for that array element.

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top() >= arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{

    return 0;
}