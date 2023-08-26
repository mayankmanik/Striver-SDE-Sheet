#include <bits/stdc++.h>
using namespace std;

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

/* An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */

bool isValid(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (c == '(' or c == '{' or c == '[')
            st.push(c);
        else
        {
            if (!st.empty())
            {
                if (c == ')')
                {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                else if (c == '}')
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
                else if (c == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{

    return 0;
}