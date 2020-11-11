/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

bool dfs(int src, bool visited[], int par, vector<int>* &adj)
{
    visited[src] = true;

    for (auto child : adj[src])
    {
        if (visited[child] == false)
        {
            if (dfs(child, visited, src, adj))
                return true;
        }
        else if (child != par)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    bool visited[V];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (dfs(i, visited, i, g))
                return true;
        }
    }
    return false;
}