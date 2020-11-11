// M : input matrix
// N : size of the matrix

// DFS on 2D matrix
// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/?track=amazon-graphs&batchId=192
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[105][105];

bool isvalid(vector<vector<int>>& adj, int N, int x, int y)
{
    if (x >= 0 and x<N and y >= 0 and y < N and (adj[x][y] == 1 or adj[x][y] == 2 or adj[x][y] == 3))
        return true;
    return false;
}
void dfs(vector<vector<int>> &adj, int x, int y, int N)
{
    visited[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        if (isvalid(adj, N, x + dx[k], y + dy[k]) and (visited[x + dx[k]][y + dy[k]] == false))
        {
            dfs(adj, x + dx[k], y + dy[k], N);
        }
    }
}
bool is_possible(vector <vector <int>> &adj, int N)
{
    memset(visited, false, sizeof(visited));

    int src_x, src_y, des_x, des_y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (adj[i][j] == 1)
            {
                src_x = i;
                src_y = j;
            }
            if (adj[i][j] == 2)
            {
                des_x = i;
                des_y = j;
            }
        }
    }
    dfs(adj, src_x, src_y, N);

    return (visited[des_x][des_y] == true);
}
