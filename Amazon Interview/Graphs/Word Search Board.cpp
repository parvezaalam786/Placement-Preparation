/*
https://www.interviewbit.com/problems/word-search-board/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells
are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.

===>  The same letter cell may be used more than once.
*/


int dx[4] = {0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1};

bool DFS(vector<string> &adj, string& B, int idx, int i, int j)
{
	if (idx == B.length())
		return true;
	int n = adj.size();
	int m = adj[0].size();
	if (i<0 or i >= n or j<0 or j >= m)
		return false;
	if (adj[i][j] != B[idx])
		return false;
	for (int k = 0; k < 4; k++)
	{
		if (DFS(adj, B, idx + 1, i + dx[k], j + dy[k]))
			return true;
	}
	return false;
}

int Solution::exist(vector<string> &A, string B)
{
	if (B.length() == 0)
		return 1;
	int n = A.size();
	if (n == 0)
		return 0;
	int m = A[0].size();
	if (m == 0)
		return 0;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == B[0])
			{
				if (DFS(A, B, 0, i, j))
					return 1;
			}
		}
	}
	return 0;
}
