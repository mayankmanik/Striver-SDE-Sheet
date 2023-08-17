#include <bits/stdc++.h>
using namespace std;

/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway
station so that no train is kept waiting. Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure
time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance
of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
*/

int findPlatform(int arr[], int dep[], int n)
{
    int plat_need = 1, ans = 1;
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0;

    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat_need++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            plat_need--;
            j++;
        }
        ans = max(ans, plat_need);
    }
    return ans;
}

int main()
{

    return 0;
}