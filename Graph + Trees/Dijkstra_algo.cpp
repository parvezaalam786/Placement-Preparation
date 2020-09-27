#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

vector<pair<int, int> > adj[1001];

void solve()
{
	int n, m, a, b, w;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dist(n + 1, inf);
	pq.push({0, 1});  // distance and node
	dist[1] = 0;

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int curr_d = pq.top().first;
		pq.pop();

		for (pair<int, int> edge : adj[curr])
		{
			if (curr_d + edge.second < dist[edge.first])
			{
				dist[edge.first] = curr_d + edge.second;
				pq.push({dist[edge.first], edge.first});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";

}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}


/*
input:

6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5

Output:
0 3 8 14 11 2
*/