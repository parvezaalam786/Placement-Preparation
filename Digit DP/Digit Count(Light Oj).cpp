#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
////http://www.lightoj.com/volume_showproblem.php?problem=1122


int dp[12][12];  //digits and previous digit

int fun(int n, vector<int> arr, int pos = 0, int prev = 0)
{
	int res = 0;
	if (dp[pos][prev] != -1)
		return dp[pos][prev];
	if (pos == n)
	{
		return 1;
	}
	for (int j = 0; j < arr.size(); j++)
	{
		if (prev == 0 or (abs(prev - arr[j]) <= 2))
			res += fun(n, arr, pos + 1, arr[j]);
	}
	return dp[pos][prev] = res;
}

void solve()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int m, n;
		cin >> m >> n;
		vector<int> arr(m);
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		memset(dp, -1, sizeof(dp));

		int ans = fun(n, arr);
		cout << "Case " << t << ": " << ans << "\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
