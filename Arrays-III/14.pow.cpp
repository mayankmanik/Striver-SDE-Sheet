#include <bits/stdc++.h>
using namespace std;

// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// O(log(n))- Time Complexity

double myPow(double x, int n)
{
    long temp = n;
    double ans = 1.0;
    if (temp < 0)
        temp = abs(temp);
    while (temp > 0)
    {
        if (temp & 1)
        {
            ans = ans * x;
            temp--;
        }
        else
        {
            x = x * x;
            temp /= 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}

int main()
{

    return 0;
}