/*
Graph Coloring: Given a graph of vertices and edges, you want to color the
nodes in such a way that no two adjacent vertices share a colour, using the
fewwst number of colours

m^V possibilities to color the nodes
*/


#include<bits/stdc++.h>
using namespace std;

// naive solution by coloring all the nodes and checking it
const int V = 4;
bool isSafe(bool graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] and color[i] == color[j])
                return false;
        }
    }
    return true;
}

bool graphColoring(bool graph[V][V], int m, int i, int color[V])
{
    if (i == V)
    {
        if (isSafe(graph, color))
        {
            for (int i = 0; i < V; i++)
                cout << color[i] << " ";
            return true;
        }
        return false;
    }

    for (int j = 1; j <= m; j++)
    {
        color[i] = j;
        if (graphColoring(graph, m, i + 1, color))
            return true;
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