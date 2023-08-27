#include <bits/stdc++.h>
using namespace std;

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Time Complexity - 0(1)

class MinStack
{
public:
    stack<long> st;
    long mini;
    MinStack()
    {
        while (!st.empty())
            st.pop();
        mini = INT_MAX;
    }

    void push(int val)
    {
        long value = val;
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        else
        {
            if (value < mini)
            {
                st.push(2 * value - 1ll * mini);
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        long long val = st.top();
        st.pop();
        if (val < mini)
        {
            mini = 2 * mini - val;
        }
    }

    int top()
    {
        long long val = st.top();
        if (val < mini)
            return mini;
        return val;
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{

    return 0;
}