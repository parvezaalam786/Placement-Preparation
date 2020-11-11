const int maxn = 100005;
vector<int> adj[maxn];
bool visited[maxn];
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
}

int dfs(int src, int& res)
{
    visited[src] = true;
    int componentNodes = 0;
    for (auto node : adj[src])
    {
        if (visited[node])
            continue;

        int subtreeNodes = dfs(node, res);

        if (subtreeNodes % 2 == 0)
            res++;
        else
            componentNodes += subtreeNodes;
    }
    return (componentNodes + 1);
}

int Solution::solve(int A, vector<vector<int> > &B)
{
    init();
    for (auto i : B)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int res = 0;
    dfs(1, res);
    return res;
}
