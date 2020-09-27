// Question Link: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/

#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

//DSU Part
int par[10010];
int Rank[10010];
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
	if (a == b) return;

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
	for (int i = 1; i <= 10000; i++)
		par[i] = -i, Rank[i] = 1;
}

//Graph part
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
	cout << mst_weight;

}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
