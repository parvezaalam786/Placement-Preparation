// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

/*
adj : adjacency list of the graph
V : Number of vertices
s,e : End vertices of the given edge
*/

void dfs(int src, bool visited[], list<int>* &adj)
{
    visited[src] = true;
    for (auto child : adj[src])
    {
        if (visited[child] == false)
            dfs(child, visited, adj);
    }
}



bool isBridge(list<int> adj[], int V, int s, int e)
{
    bool visited1[V + 1], visited2[V + 1];
    for (int i = 0; i < V; i++)
    {
        visited1[i] = false;
        visited2[i] = false;
    }

    dfs(s, visited1, adj);
    adj[s].remove(e);
    adj[e].remove(s);
    dfs(s, visited2, adj);


    for (int i = 0; i < V; i++)
        if (visited1[i] != visited2[i])
            return true;

    return false;



}