#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

const int maxn = 200010;

vector<int> adj[maxn];
int LIS[maxn];
int val[maxn];
int ans[maxn];

void dfs(int node, int par, int len)
{
	auto lb = lower_bound(LIS, LIS + len, val[node]);
	int temp = *lb;
	if (lb == LIS + len)
		ans[node] = len + 1;
	else
		ans[node] = len;
	*lb = val[node];
	for (auto x : adj[node])
	{
		if (x != par)
		{
			dfs(x, node, ans[node]);
		}
	}
	*lb = temp;
}


void solve()
{
	int N, u, v;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> val[i];
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i <= N; i++)
		LIS[i] = inf;
	dfs(1, -1, 1);
	for (int i = 1; i <= N; i++)
		cout << ans[i] << "\n";
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
