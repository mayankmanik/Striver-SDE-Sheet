#include <bits/stdc++.h>
using namespace std;

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function,but instead be stored inside 
the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements
denote the elements that should be merged,and the last n elements are set to 0 
and should be ignored. nums2 has a length of n.
*/

// O(1)-Space Complexity

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1;
    int ind = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[ind] = nums1[i];
            i--;
        }
        else
        {
            nums1[ind] = nums2[j];
            j--;
        }
        ind--;
    }
    while (i >= 0)
    {
        nums1[ind] = nums1[i];
        i--;
        ind--;
    }
    while (j >= 0)
    {
        nums1[ind] = nums2[j];
        j--;
        ind--;
    }
}
int main()
{

    return 0;
}