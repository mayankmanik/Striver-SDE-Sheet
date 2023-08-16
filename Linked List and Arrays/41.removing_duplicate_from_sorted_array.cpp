#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each
// unique element appears only once. The relative order of the elements should be kept the same.
// Since it is impossible to change the length of the array in some languages,you must instead have
// the result be placed in the first part of the array nums. More formally, if there are k elements
// after removing the duplicates, then the first k elements of nums should hold the final result.
// It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// O(1)-Space Complexity

int removeDuplicates(vector<int> &nums)
{
    int k = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[k - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
int main()
{

    return 0;
}