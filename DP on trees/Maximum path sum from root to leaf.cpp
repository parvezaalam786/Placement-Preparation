#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

/*
Find the Maximum path sum from root to leaf.

We can do it by storing at each node maximum sum from it to leaf.
For a node x we will take the maximum node value of its child and add it to current node.
*/
map<int, int> dp;
void go(vector<int> v[], int *a, int u, int par)
{
	dp[u] = a[u];
	int mx = 0;
	for (int child : v[u])
	{
		if (child == par)
			continue;
		go(v, a, child, u);
		mx = max(mx, dp[child]);
	}
	dp[u] += mx;
}

void solve()
{
	int n = 14;
	vector<int> v[n + 1];
	v[1].push_back(2), v[2].push_back(1);
	v[1].push_back(3), v[3].push_back(1);
	v[1].push_back(4), v[4].push_back(1);
	v[2].push_back(5), v[5].push_back(2);
	v[2].push_back(6), v[6].push_back(2);
	v[3].push_back(7), v[7].push_back(3);
	v[4].push_back(8), v[8].push_back(4);
	v[4].push_back(9), v[9].push_back(4);
	v[4].push_back(10), v[10].push_back(4);
	v[5].push_back(11), v[11].push_back(5);
	v[5].push_back(12), v[12].push_back(5);
	v[7].push_back(13), v[13].push_back(7);
	v[7].push_back(14), v[14].push_back(7);
	int a[] = { 0, 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8 };
	go(v, a, 1, 0);
	cout << dp[1] << endl;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
