#include <bits/stdc++.h>
using namespace std;

// You are given two positive integers N and M. You have to find the Nth root of M.

double product(double a, int b)
{
    double ans = 1.0;
    for (int i = 1; i <= b; i++)
        ans *= a;
    return ans;
}

double findNthRootOfM(int n, int m)
{
    double low = 0, high = m;
    double eps = 1e-7;
    while ((high - low) > eps)
    {
        double mid = low + (high - low) / 2.0;
        if (product(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main()
{

    return 0;
}