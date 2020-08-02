/*
https://www.spoj.com/problems/GOT/
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
The timer acts as an index in quering tree.

Properties of Flat tree:

1)If we want to query the number of nodes lying in the subtree of node x we can find it by going to the
starting time and ending time of node x in Flat tree and taking all the nodes lying inbetween.

2)In Flat tree all the node which lies between src and des two times does not lie in the path
from source to destination.

3)For path between node 'a' to node 'b' there are two cases:
    i) 'b' lies in the subtree of node 'a' , we can check it by there LCA
    ii)'b' does not lie in the subtree of node 'a'

    For  query: a b
    if LCA(a,b) == a:
        Query = S[a] to S[b] in flat tree
    else
        Query = T[a] to S[b] +LCA(a,b)
*/

const int maxN = 21; //For LCA
const int maxn = 100010; //For size
const int BLOCK = 700; //For MOS Algorithm

vector<int> adj[maxn];

/*
nodeF = for frequency of node number
eleF = for frequency of the number assigned to the nodes
*/
int nodeF[maxn], eleF[maxn], level[maxn];
int LCA[maxn][maxN], val[maxn], res[2 * maxn];

int S[maxn], T[maxn], FT[2 * maxn]; //Start, End, Flat Tree
int timer;

struct query
{
	int l, r, c, idx, lca;
};

query Q[2 * maxn];

void dfs(int node, int par, int lvl) //for creating the Flat Tree and for initializing the first column of LCA
{
	level[node] = lvl;
	LCA[node][0] = par;

	S[node] = timer;
	FT[timer] = node;
	timer++;

	for (auto child : adj[node])
	{
		if (child == par)
			continue;
		dfs(child, node, lvl + 1);
	}

	T[node] = timer;
	FT[timer] = node;
	timer++;
}

void init(int n) // for creating the LCA matrix
{
	for (int j = 1; j < maxN; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (LCA[i][j - 1] != -1)
			{
				int par = LCA[i][j - 1];
				LCA[i][j] = LCA[par][j - 1];
			}
		}
	}
}

int getLCA(int a, int b)
{
	if (level[b] < level[a])
		swap(a, b);
	int d = level[b] - level[a];

	while (d > 0)
	{
		int i = log2(d);
		b = LCA[b][i];
		d -= (1 << i);
	}
	if (a == b)
		return a;

	for (int i = maxN - 1; i >= 0; i--)
	{
		if (LCA[a][i] != -1 and (LCA[a][i] != LCA[b][i]))
		{
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}

bool cmp(query a, query b)
{
	int x = a.l / BLOCK;
	int y = b.l / BLOCK;

	if (x != y)
		return x < y;
	else
		return a.r < b.r;
}

void add(int idx)
{
	int node = FT[idx];
	nodeF[node]++;
	if (nodeF[node] == 1)// if the node appears exactly once in the Flat tree it means it lies in the path(Prop:2)
	{
		int c = val[node];
		eleF[c]++;
	}
	else                // if frequency is greater than 1 then the node does not lies in the path (Prop:2)
	{
		int c = val[node];
		eleF[c]--;
	}
}

void remove(int idx)
{
	int node = FT[idx];
	nodeF[node]--;
	if (nodeF[node] == 1) //Prop:2
	{
		int c = val[node];
		eleF[c]++;
	}
	else  // Prop:2
	{
		int c = val[node];
		eleF[c]--;
	}
}

void solve()
{
	int n, q, a, b, c;
	int t = 0;
	while (cin >> n)
	{
		if (t > 0)
			cout << "\n";
		t++;
		cin >> q;

		for (int i = 0; i <= n; i++)
		{
			adj[i].clear();
			eleF[i] = 0;
			nodeF[i] = 0;
		}
		for (int i = 1; i <= q; i++)
		{
			res[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			cin >> val[i];

		for (int i = 1; i < n; i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		timer = 1;
		memset(LCA, -1, sizeof(LCA));
		dfs(1, -1, 0);
		init(n);

		for (int i = 1; i <= q; i++)
		{
			cin >> a >> b >> c;
			if (S[a] > S[b])
			{
				swap(a, b);
			}
			int lca = getLCA(a, b);
			Q[i].idx = i, Q[i].c = c;

			if (a == lca)
			{
				Q[i].l = S[a];
				Q[i].r = S[b];
				Q[i].lca = -1;
			}
			else
			{
				Q[i].l = T[a];
				Q[i].r = S[b];
				Q[i].lca = lca;
			}
		}
		sort(Q + 1, Q + q + 1, cmp);

		int ML = 1, MR = 0;

		for (int i = 1; i <= q; i++)
		{
			int L = Q[i].l;
			int R = Q[i].r;
			int c = Q[i].c;
			int lca = Q[i].lca;
			int idx = Q[i].idx;

			while (MR < R)
			{
				MR++;
				add(MR);
			}
			while (ML > L)
			{
				ML--;
				add(ML);
			}
			while (MR > R)
			{
				remove(MR);
				MR--;
			}
			while (ML < L)
			{
				remove(ML);
				ML++;
			}
			if (eleF[c] > 0) // not checking lca because 'b' lies in subtree of 'a'
				res[idx] = 1;

			if ((lca != -1) and val[lca] == c) // checking lca as lca also lies in the path from a to b in this case
				res[idx] = 1;
		}

		for (int i = 1; i <= q; i++)
		{
			if (res[i] == 1)
				cout << "Find" << "\n";
			else
				cout << "NotFind" << "\n";
		}
	}

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
