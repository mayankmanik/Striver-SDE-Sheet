#include <bits/stdc++.h>
using namespace std;

// You are given N number of books. Every ith book has Ai number of pages.
// You have to allocate contiguous books to M number of students. There can be many ways or
// permutations to do so. In each permutation, one of the M students will be allocated the maximum 
// number of pages. Out of all these permutations, the task is to find that particular permutation
//  in which the maximum number of pages allocated to a student is the minimum of those in all the
//  other permutations and print this minimum value.

// Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.

// Time Complexity - O(NLog(N))

bool canAllocate(int A[], int n, int m, int mid)
{
    int no = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + A[i] <= mid)
            sum += A[i];
        else
        {
            no++;
            if (no > m or A[i] > mid)
                return false;
            sum = A[i];
        }
    }

    return true;
}
int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;
    int ans = 0;
    int low = A[0];
    int high = accumulate(A, A + N, 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canAllocate(A, N, M, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{

    return 0;
}