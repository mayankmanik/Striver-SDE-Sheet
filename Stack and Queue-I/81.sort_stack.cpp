#include <bits/stdc++.h>
using namespace std;

// You're given a stack consisting of 'N' integers. Your task is to sort this stack in descending order 
// using recursion.

void insert(stack<int> &st, int x)
{
    if (st.empty() or st.top() <= x)
    {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    insert(st, x);
    st.push(y);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    sortStack(st);
    insert(st, x);
}

int main()
{

    return 0;
}