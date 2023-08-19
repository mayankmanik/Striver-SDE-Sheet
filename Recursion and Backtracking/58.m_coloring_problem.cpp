#include <bits/stdc++.h>
using namespace std;

// Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M 
// colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph
//  means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

bool possible(int node, vector<int> &color, bool graph[101][101], int n, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node and graph[i][node] == 1 and color[i] == col)
            return false;
    }
    return true;
}
bool canColored(int node, bool graph[101][101], int m, int n, vector<int> &color)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (possible(node, color, graph, n, i))
        {
            color[node] = i;
            if (canColored(node + 1, graph, m, n, color))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    return canColored(0, graph, m, n, color);
}
int main()
{

    return 0;
}