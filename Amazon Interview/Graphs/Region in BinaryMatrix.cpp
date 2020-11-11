int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

int cnt = 0;
void dfs(vector<vector<int>> &adj, vector<vector<bool>> &visited, int i, int j, int n, int m)
{
    visited[i][j] = true;
    cnt++;

    for (int k = 0; k < 8; k++)
    {
        if (i + dx[k] >= 0 and i + dx[k] < n and j + dy[k] >= 0 and j + dy[k] < m and visited[i + dx[k]][j + dy[k]] == false and adj[i + dx[k]][j + dy[k]] == 1)
        {
            dfs(adj, visited, i + dx[k], j + dy[k], n, m);
        }
    }
}

int Solution::solve(vector<vector<int> > &A)
{
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false and A[i][j] == 1)
            {
                dfs(A, visited, i, j, n, m);
                ans = max(ans, cnt);
                cnt = 0;
            }

        }
    }
    return ans;
}
