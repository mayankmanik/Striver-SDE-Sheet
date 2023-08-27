#include <bits/stdc++.h>
using namespace std;

// Design an algorithm that collects daily price quotes for some stock and returns the span of that 
// stock's price for the current day.The span of the stock's price in one day is the maximum number
// of consecutive days (starting from that day and going backward)for which the stock price was less 
// than or equal to the price of that day.

// Amortized Time Complexity - O(1)

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int cnt = 1;
        while (!st.empty() and st.top().first <= price)
        {
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

int main()
{

    return 0;
}