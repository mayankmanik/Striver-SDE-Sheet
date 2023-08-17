#include <bits/stdc++.h>
using namespace std;

/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
*/

struct Job
{
    int id;
    int dead;
    int profit;
};

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans(2, 0);
    sort(arr, arr + n, cmp);
    int mxtm = 0;
    for (int i = 0; i < n; i++)
        mxtm = max(mxtm, arr[i].dead);
    vector<int> tm(mxtm + 1, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (tm[j] == -1)
            {
                tm[j] = arr[i].id;
                ans[0]++;
                ans[1] += arr[i].profit;
                break;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}