#include<bits/stdc++.h>
using namespace std;
/// with the help of this concept we can check if a node lies in the subtree of another node.
vector<int> adj[100010];
int In[100010];
int Out[100010];
bool visited[100010];
int timer = 1;

void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int node)
{
	visited[node] = true;
	In[node] = timer++;
	for(int child:adj[node])
	{
		if(visited[child]==false)
		{
			dfs(child);
		}
	}
	Out[node] = timer++;
}

///check if x is in subtree of y
void query(int x,int y)
{
	if(In[x]>In[y] && Out[x]<Out[y])
		cout<<x<<" is in subtree of "<<y<<"\n";
	else
		cout<<x<<" is not in subtree of "<<y<<"\n";
}
int main()
{
	int nodes,edges;
	//cin>>nodes>>edges;
	nodes = 5;
	addEdge(1,2);
	addEdge(2,3);
	addEdge(2,4);
	addEdge(4,5);

	dfs(1);

	query(2,1);
	query(3,2);
	query(3,4);
	return 0;

}