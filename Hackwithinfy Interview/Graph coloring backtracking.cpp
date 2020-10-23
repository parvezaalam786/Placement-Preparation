#include<bits/stdc++.h>
using namespace std;

const int V = 4;

bool isSafe(int v, int c, bool graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] and color[i] == c)
            return false;
    }
    return true;
}

bool graphColoring(bool graph[V][V], int m, int i, int color[])
{
    if (i == V)
    {
        for (int i = 0; i < V; i++)
            cout << color[i] << " ";
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        color[i] = c;
        if (isSafe(i, c, graph, color))
        {
            if (graphColoring(graph, m, i + 1, color) == true)
                return true;
        }
        color[i] = 0;
    }
    return false;
}

int main()
{
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3;
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoring(graph, m, 0, color))
    {
        cout << "solution does not exist";
    }
    else
        cout << "solution exists";

    return 0;
}