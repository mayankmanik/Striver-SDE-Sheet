#include <bits/stdc++.h>
using namespace std;

// Implement the MedianFinder class:
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10^(-5) of the actual 
// answer will be accepted.

class MedianFinder
{
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;

    void addNum(int num)
    {
        if (maxpq.empty() or maxpq.top() > num)
            maxpq.push(num);
        else
            minpq.push(num);
        if (maxpq.size() > minpq.size() + 1)
        {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if (minpq.size() > maxpq.size())
        {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }

    double findMedian()
    {
        if (maxpq.size() == minpq.size())
            return (maxpq.top() + minpq.top()) / 2.0;
        return maxpq.top();
    }
};

int main()
{

    return 0;
}