#include <bits/stdc++.h>
using namespace std;
// Given an array a[]. The task is to find the inversion count of a[]. 
// Where two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Using Merge Sort 

int mergeArr(int arr[], int si, int mid, int ei)
{
    int ind1 = si, ind2 = mid + 1, x = 0;
    int cnt = 0;
    int temp[ei - si + 1];

    while (ind1 <= mid and ind2 <= ei)
    {
        if (arr[ind1] <= arr[ind2])
        {
            temp[x++] = arr[ind1++];
        }
        else
        {
            temp[x++] = arr[ind2++];
            cnt += (mid + 1 - ind1);
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

int countInversion(int arr[], int si, int ei)
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

int getCount(int arr[], int n)
{
    return countInversion(arr, 0, n - 1);
}
int main()
{

    return 0;
}