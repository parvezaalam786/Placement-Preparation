#include<bits/stdc++.h>
using namespace std;
map<int,list<int>> adjList;
void addEdge(int u,int v)
{
	adjList[u].push_back(v);
	///adjList[v].push_back(u);
}
void countPathsUtil(int u,int v,bool visited[],int &pathCount)
{
	visited[u] = true;
	if(u==v)
		pathCount++;
	else
	{
		for(auto i:adjList[u])
		{
			if(!visited[i])
				countPathsUtil(i,v,visited,pathCount);
		}
	}
	visited[u] = false;
}
int countPaths(int src,int des,int nodes)
{
	bool visited[nodes];
	memset(visited,false,sizeof(visited));
	int pathCount = 0;
	countPathsUtil(src,des,visited,pathCount);
	return pathCount;
}

int main()
{
	int nodes = 4;
	int edges = 6;
	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(2,0);
	addEdge(2,1);
	addEdge(1,3);
	int src = 2,des = 3;
	cout<<countPaths(src,des,nodes);
	return 0;
}