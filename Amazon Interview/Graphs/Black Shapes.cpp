// https://www.interviewbit.com/problems/black-shapes/

int dx[4] = {0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1};

bool isvalid(auto &adj, auto &visited, int i, int j)
{
	int n = adj.size();
	int m = adj[0].size();
	if (i<0 or i >= n or j<0 or j >= m or visited[i][j] == true or adj[i][j] == 'O')
		return false;
	return true;
}

void DFS(vector<string> &adj, int i, int j, auto &visited)
{
	visited[i][j] = true;
	for (int k = 0; k < 4; k++)
	{
		if (isvalid(adj, visited, i + dx[k], j + dy[k]))
			DFS(adj, i + dx[k], j + dy[k], visited);
	}
}

int Solution::black(vector<string> &A)
{
	int n = A.size();
	int m = A[0].size();
	int cnt = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == 'X' and visited[i][j] == false)
			{
				DFS(A, i, j, visited);
				cnt++;
			}
		}
	}
	return cnt;

}
