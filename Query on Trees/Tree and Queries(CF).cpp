#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
/*
Application of MO'S algorithm on trees
https://codeforces.com/problemset/problem/375/D
*/

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

/*
Steps:
1) We will flatten the tree using dfs and timer concept
2) Now we will apply the MOS algorithm on trees.
	For a node x, the children's of x can be found in flat tree by the starting and ending
	time of node x, and after taking all the nodes lying inbetween start and end time of node x
	we will do our query.
*/

const int maxn = 100001;
const int BLK = 700; //BLK = sqrt(N)
vector<int> adj[maxn];
int S[maxn], T[maxn], FT[2 * maxn], col[maxn];

/*
nodeF = Node frequency represents that this node lies in the subtree of the current node for which we are adding the elements
eleF = Element frequency represents the frequency of colors (i.e. value of the node)
FF = Frequency of frequency
*/

int nodeF[maxn], eleF[maxn], FF[maxn], bucket[maxn];

int ans[maxn], n;
int timer;

struct query
{
	int l;
	int r;
	int idx;
	int k;
};

query Q[maxn];

void dfs(int node, int par)
{
	S[node] = timer;
	FT[timer] = node;
	timer++;
	for (int child : adj[node])
	{
		if (child == par)
			continue;
		dfs(child, node);
	}
	T[node] = timer;
	FT[timer] = node;
	timer++;
}

bool cmp(query a, query b)
{
	int x = a.l / BLK;
	int y = b.l / BLK;
	if (x != y)
		return x < y;
	if (x % 2)
		return a.r < b.r;
	else
		return a.r > b.r;

}

int getBlock(int idx)
{
	return (idx + BLK - 1) / BLK;
}

void add(int idx)
{
	int node = FT[idx];
	int c = col[node];
	nodeF[node]++;

	if (nodeF[node] == 2) //if the frequency of the node becomes 2 we will add this node because every node in subtree appears twice in flat tree.
	{
		eleF[c]++;
		FF[eleF[c]]++;
		bucket[getBlock(eleF[c])]++;

		FF[eleF[c] - 1]--;
		bucket[getBlock(eleF[c] - 1)]--;
	}
}
void remove(int idx)
{
	int node = FT[idx];
	int c = col[node];
	nodeF[node]--;

	if (nodeF[node] == 1) // removing of the frequency becomes 1
	{
		eleF[c]--;
		FF[eleF[c]]++;
		bucket[getBlock(eleF[c])]++;

		FF[eleF[c] + 1]--;
		bucket[getBlock(eleF[c] + 1)]--;
	}
}
int getAns(int k, int n)
{
	int ans = 0;
	int LB = getBlock(k);
	int RB = getBlock(n);
	if (LB == RB)
	{
		for (int i = k; i <= n; i++)
			ans += FF[i];
	}
	else
	{	//This is standard MOS thing
		for (int i = k; i <= LB * BLK; i++)
			ans += FF[i];
		for (int i = LB + 1; i < RB; i++)
			ans += bucket[i];
		for (int i = RB * BLK + 1; i <= n; i++)
			ans += FF[i];
	}
	return ans;
}
void solve()
{
	int q, a, b, k;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> col[i];
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	timer = 1;
	dfs(1, -1);
	for (int i = 1; i <= q; i++)
	{
		cin >> a >> k;
		Q[i].l = S[a];
		Q[i].r = T[a];
		Q[i].k = k;
		Q[i].idx = i;
	}
	sort(Q + 1, Q + q + 1, cmp);
	int ML = 1, MR = 0;
	for (int i = 1; i <= q; i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
		int idx = Q[i].idx;
		k = Q[i].k;

		while (MR < R)
			MR++, add(MR);
		while (ML > L)
			ML--, add(ML);
		while (MR > R)
			remove(MR), MR--;
		while (ML < L)
			remove(ML), ML++;
		ans[idx] = getAns(k, n);
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
