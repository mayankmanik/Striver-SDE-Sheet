#include <bits/stdc++.h>
using namespace std;

/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({start[i], end[i]});
    }
    sort(vp.begin(), vp.end(), cmp);
    int ans = 0, finishTime = -1;
    for (int i = 0; i < n; i++)
    {
        if (finishTime < vp[i].first)
        {
            ans++;
            finishTime = vp[i].second;
        }
    }
    return ans;
}

int main()
{

    return 0;
}