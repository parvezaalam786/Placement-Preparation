// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/


vector <int> bfs(vector<int> g[], int N)
{
	vector<int> ans;
	bool visited[N];
	memset(visited, false, sizeof(visited));

	queue<int> que;
	que.push(0);
	visited[0] = true;
	while (!que.empty())
	{
		int x = que.front();
		ans.push_back(x);
		que.pop();

		for (auto child : g[x])
		{
			if (visited[child] == false)
			{
				que.push(child);
				visited[child] = true;
			}
		}
	}

	return ans;
}