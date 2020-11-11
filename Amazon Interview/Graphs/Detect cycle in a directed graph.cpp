/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool dfs(int src, bool visited[], bool currRec[], vector<int>* &adj)
{
    if (visited[src] == false)
    {
        visited[src] = true;
        currRec[src] = true;

        for (auto child : adj[src])
        {
            if (visited[child] == false and dfs(child, visited, currRec, adj))
                return true;
            else if (currRec[child])
                return true;
        }
    }
    currRec[src] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V];
    bool currRec[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        currRec[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            bool cycle = dfs(i, visited, currRec, adj);
            if (cycle)
                return true;
        }
    }
    return false;
}
