// https://www.hackerrank.com/challenges/kruskalmstrsub/problem
#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
};

class Set {
public:
    int rank;
    int parent;
};
int find(Set *set, int i) {
    if (set[i].parent != i) {
        set[i].parent = find(set, set[i].parent); //recursively fiond parent of the set
    }
    return set[i].parent;
}
void Union(Set *set, int v1, int v2) {
    int v1_root = find(set, v1);
    int v2_root = find(set, v2);
    if (set[v1_root].rank < set[v2_root].rank) {
        set[v1_root].parent = v2_root;
    }
    else if (set[v1_root].rank > set[v2_root].rank) {
        set[v2_root].parent = v1_root;
    }
    else {
        set[v2_root].parent = v1_root;
        set[v1_root].rank++;
    }
}

bool cmp(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}
void Kruskals(Edge *input, int n, int e)
{
    sort(input, input + e, cmp); //Sort the array on the basis of the weight
    Edge *output = new Edge[n - 1]; //There will bee n-1 edges for MST formed
    Set *set = new Set[n];//Initialize the sets for all vertices
    for (int i = 0; i < n; i++) {
        set[i].rank = 0;
        set[i].parent = i;//Assign the parent of all vertices to itself so that all belong to different set
    }
    int counter = 0, i = 0;
    while (counter < n - 1) {
        Edge currentEdge = input[i];//Taken the edge with minimum weight
        int sourceParent = find(set, currentEdge.src); //Found parent of source vertex
        int destinationParent = find(set, currentEdge.dest); //Found parent of destination vertex
        if (sourceParent != destinationParent) { //if both lie in different set
            output[counter] = currentEdge;//we will insert the edge in mst
            Union(set, sourceParent, destinationParent); //Union of src and dest vertex
            counter++;
        }
        i++;
    }
    int totalWeight = 0;
    for (int i = 0; i < n - 1; i++) {
        totalWeight += output[i].weight;
        cout << output[i].src << "--" << output[i].dest << "with weight " << output[i].weight << endl;
    }
    cout << "Total weight:" << totalWeight << endl;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    Edge *input = new Edge[edges];
    for (int i = 0; i < edges; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    Kruskals(input, nodes, edges);

    return 0;
}

/*
inputs:
7
8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3
outputs:
*/