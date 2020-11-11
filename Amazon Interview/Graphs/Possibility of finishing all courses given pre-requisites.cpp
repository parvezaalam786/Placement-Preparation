// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

int Solution::solve(int A, vector<int> &B, vector<int> &C)
{
	vector<int> adj[A + 1];
	vector<int> indegree(A + 1, 0);

	int n = B.size();

	for (int i = 0; i < n; i++)
	{
		adj[B[i]].push_back(C[i]);
		indegree[C[i]]++;
	}

	queue<int> que;
	int cnt = 0;
	for (int i = 1; i <= A; i++)
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	bool visited[A + 1];
	memset(visited, false, sizeof(visited));

	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		visited[curr] = true;
		cnt++;

		for (auto node : adj[curr])
		{
			indegree[node]--;
			if (indegree[node] == 0 and visited[node] == false)
				que.push(node);
		}
	}
	return (cnt == A);
}
