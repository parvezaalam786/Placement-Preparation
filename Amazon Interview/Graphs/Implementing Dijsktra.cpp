
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?track=amazon-graphs&batchId=192
/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1000000000;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int curr_node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        for (int i = 0; i < V; i++)
        {
            if (g[curr_node][i] != 0 and dist[i] > g[curr_node][i] + curr_dist)
            {
                dist[i] = curr_dist + g[curr_node][i];
                pq.push({dist[i], i});
            }
        }
    }
    return dist;

}