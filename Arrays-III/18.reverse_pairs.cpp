#include <bits/stdc++.h>
using namespace std;

// Given an integer array arr, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < arr.length and
// arr[i] > 2 * arr[j].

// O(nlog(n))-Time Complexity

int mergeArr(vector<int> &arr, int si, int mid, int ei)
{
    int ind1 = si, ind2 = mid + 1, x = 0;
    int cnt = 0;
    int temp[ei - si + 1];
    int j = mid + 1;
    for (int i = si; i <= mid; i++)
    {
        while (j <= ei and arr[i] > 2ll * arr[j])
            j++;
        cnt += (j - (mid + 1));
    }
    while (ind1 <= mid and ind2 <= ei)
    {
        if (arr[ind1] <= arr[ind2])
        {
            temp[x++] = arr[ind1++];
        }
        else
        {
            temp[x++] = arr[ind2++];
        }
    }
    while (ind1 <= mid)
    {
        temp[x++] = arr[ind1++];
    }
    while (ind2 <= ei)
    {
        temp[x++] = arr[ind2++];
    }
    for (int i = 0, j = si; i < ei - si + 1; i++, j++)
    {
        arr[j] = temp[i];
    }
    return cnt;
}

int countInversion(vector<int> &arr, int si, int ei)
{
    int cnt = 0, mid;
    if (ei > si)
    {
        mid = si + (ei - si) / 2;
        cnt += countInversion(arr, si, mid);
        cnt += countInversion(arr, mid + 1, ei);
        cnt += mergeArr(arr, si, mid, ei);
    }
    return cnt;
}

int reversePairs(vector<int> &arr)
{
    return countInversion(arr, 0, arr.size() - 1);
}
int main()
{

    return 0;
}