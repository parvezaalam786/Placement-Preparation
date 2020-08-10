/*
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
/*
Spanning tree: A tree which have all the vertices connected such that there is no cycle.
Minimum Spanning Tree: In a weighted graph, we will include those edges which have minimum weight
 and all the conditions of spanning tree is satisfied.
*/

/*
Kruskal Algorithm: It is a greedy approach.
1) We will sort the given edges in ascending order by their weights
2) We will pick the edges in ascending order such that cycle is not formed.
*/

/***********DSU Part************/

const int maxn = 100005;
int par[maxn];
int Rank[maxn];

int find(int a)
{
	if (par[a] < 0)
		return a;
	return par[a] = find(par[a]);
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (Rank[a] > Rank[b])
	{
		par[b] = a;
		Rank[a] += Rank[b];
	}
	else
	{
		par[a] = b;
		Rank[b] += Rank[a];
	}
}

bool check(int a, int b)
{
	a = find(a);
	b = find(b);
	return a == b;
}

void InitializeDSU()
{
	for (int i = 1; i < maxn; i++)
	{
		par[i] = -i;
		Rank[i] = 1;
	}
}

/*********Graph Part********/

struct edge
{
	int a;
	int b;
	int w;
};

edge adj[100010];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
void solve()
{
	InitializeDSU();
	int N, M;
	cin >> N >> M;
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		adj[i].a = u;
		adj[i].b = v;
		adj[i].w = w;
	}
	sort(adj, adj + M, cmp);

	int mst_weight = 0;
	for (int i = 0; i < M; i++)
	{
		if (check(adj[i].a, adj[i].b) == false)
		{
			mst_weight += adj[i].w;
			Union(adj[i].a, adj[i].b);
		}
	}
	cout << mst_weight << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
