#include <bits/stdc++.h>
using namespace std;

// Implement the Min Heap data structure. For information about Heap ciick here.
// You will be given 2 types of queries:
// Insert X in the heap
// Print the minimum element from the heap and remove it.

int heapify(vector<int> &heap, int k, int &size)
{

    int l = 2 * k + 1;
    int r = 2 * k + 2;
    int smallest = k;

    if (l < size && heap[l] < heap[k])
        smallest = l;

    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != k)
    {

        int tempp = heap[k];
        heap[k] = heap[smallest];
        heap[smallest] = tempp;
        heapify(heap, smallest, size);
    }
}

void insert(vector<int> &heap, int val, int &size)
{

    heap[size] = val;
    int i = size;
    size += 1;

    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(vector<int> &heap, int &size)
{

    if (size == 1)
    {
        size -= 1;
        return heap[0];
    }

    int val = heap[0];
    heap[0] = heap[size - 1];
    size -= 1;
    heapify(heap, 0, size);
    return val;
}

vector<int> minHeap(int n, vector<vector<int>> &q)
{

    int size = 0;
    vector<int> heap(n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
            insert(heap, q[i][1], size);
        else
            ans.push_back(extractMin(heap, size));
    }
    return ans;
}

int main()
{

    return 0;
}