/*
Contribution Technique
https://codeforces.com/contest/1399/problem/E1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

struct cmp // sorting by which edge can contribute the maximum
{
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		return ((a.ff - a.ff / 2) * a.ss) > ((b.ff - b.ff / 2) * b.ss);
	}
};

multiset<pair<int, int>, cmp> s1;

const int maxn = 100005;
int sum;
vector<pair<int, int>> adj[maxn];

int dfs(int node, int par)
{
	int ans = 0; //count of leaves
	for (auto i : adj[node])
	{
		if (i.ff == par) continue;

		int temp = dfs(i.ff, node);
		s1.insert({i.ss, temp});
		sum += temp * i.ss; // calculating the path sum
		ans += temp; // leaves for the current node
	}
	if (!ans) // if the current node has no leaf then it is the leaf
		ans = 1;
	return ans;
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		sum = 0;
		s1.clear();
		int n, w;
		cin >> n >> w;
		for (int i = 0; i <= n; i++)
			adj[i].clear();

		for (int i = 0; i < n - 1; i++)
		{
			int u, v, x;
			cin >> u >> v >> x;
			adj[u].push_back({v, x});
			adj[v].push_back({u, x});
		}

		dfs(1, 0);
		int cnt = 0;
		while (sum > w)
		{
			cnt++;
			auto temp = *s1.begin();
			s1.erase(s1.begin());

			// on dividing the edge value by 2
			sum -= temp.ff * temp.ss;
			temp.ff = temp.ff / 2;
			if (temp.ff > 0)
			{
				sum += temp.ff * temp.ss;
				s1.insert(temp);
			}
		}
		cout << cnt << "\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}