// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/?track=amazon-graphs&batchId=192
/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

void DFS(int src, vector<int> *adj, int visited[], vector<int>& dfs_traversal)
{
    visited[src] = 1;
    dfs_traversal.push_back(src);

    for (auto node : adj[src])
    {
        if (visited[node] == 0)
            DFS(node, adj, visited, dfs_traversal);
    }
}


vector <int> dfs(vector<int> g[], int N)
{
    vector<int> dfs_traversal;
    int visited[N] = {0};
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
            DFS(i, g, visited, dfs_traversal);
    }
    return dfs_traversal;
}