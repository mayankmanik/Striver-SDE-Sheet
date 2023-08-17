#include <bits/stdc++.h>
using namespace std;

/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the
maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.
*/

struct Item
{
    int value;
    int weight;
};

static bool cmp(Item a, Item b)
{
    return ((a.value / double(a.weight)) > (b.value / double(b.weight)));
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    double ans = 0;
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        Item it = arr[i];
        double valperwt = (it.value / double(it.weight));

        if (W >= it.weight)
        {
            ans += it.value;
            W -= it.weight;
        }
        else
        {
            ans += valperwt * W;
            W = 0;
            break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}