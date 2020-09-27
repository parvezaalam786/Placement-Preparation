#include<bits/stdc++.h>
using namespace std;
map<int,list<int>> adjList;
void addEdge(int u,int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
int Level_nodes_BFS(int src,int l1,int nodes)
{
	bool visited[nodes];
	int level[nodes];
	for(int i=0;i<nodes;i++)
	{
		visited[i] = false;
		level[i] = 0;
	}
	level[src] = 0;
	list<int> queue;
	visited[src] = true;
	queue.push_back(src);
	level[src] = 0;

	while(!queue.empty())
	{
		src = queue.front();
		queue.pop_front();
		for(auto i:adjList[src])
		{
			if(!visited[i])
			{
				level[i] = level[src]+1;
				visited[i] = true;
				queue.push_back(i);
			}
		}
	}
	int cnt = 0;
	for(int i=0;i<nodes;i++)
	{
		if(level[i]==l1)
			cnt++;
	}
	return cnt;
}

int main()
{
	int nodes = 6;
	int edges = 5;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	int l1 = 1;
	cout<<Level_nodes_BFS(0,l1,nodes);
}