#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
/*
https://cses.fi/problemset/task/1639
*/

/*
Defining the states:
1) dp[i][x] = represents number of valid arrays upto index i such that I can place x at the ith place.

2) our final answer would be:
	ans = dp[n][1]+dp[n][2]+........+dp[n][m]

3) Now the recurrence relation formed is:
	x is in {1..m}

	if (arr[i-1] == 0 or arr[i-1] == x)
		dp[i][x] = dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1]
	else
		dp[i][x] = 0
4) Base case:
	if(i==1)
	{
		if(arr[i-1] == x or arr[i-1] == 0)
			dp[1][x] = 1;
		else
			dp[1][x] = 0
	}
*/


int fun(int n, int m, int arr[])
{
	int ans = 0;

	int dp[n + 1][m + 2];
	memset(dp, 0, sizeof(dp));

	for (int x = 1; x <= m; x++)
	{
		if (arr[0] == 0 or arr[0] == x)
			dp[1][x] = 1;
		else
			dp[1][x] = 0;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (arr[i - 1] == 0 or arr[i - 1] == x)
				dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % mod + dp[i - 1][x + 1]) % mod;
			else
				dp[i][x] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
		ans = (ans + dp[n][i]) % mod;
	return ans;
}


void solve()
{
	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = fun(n, m, arr);
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
