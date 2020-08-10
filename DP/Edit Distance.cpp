#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

/*
https://cses.fi/problemset/task/1639
*/

int fun(string a, string b)
{
	int n = a.length();
	int m = b.length();
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			//Replace, remove, add

		}
	}
	return dp[n][m];
}

void solve()
{
	string a, b;
	cin >> a >> b;

	int ans = fun(a, b);
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
