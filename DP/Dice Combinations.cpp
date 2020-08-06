/*
https://cses.fi/problemset/task/1633
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007
/*
	Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
	Each throw produces an outcome between 1 and 6.

	Since the number of ways in which we can get sum = 0 is 1(i.e. by not doing anything)
	If we make the recursive tree we will find the below recurrence relation(try for n = 7).

	dp[i] = no. of ways to throw the dice such that the sum is 0

	Recurrence relation:
	dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6]

	Base case:
		dp[i] += dp[i-x] where x is in(1...6) and i-x>=0

*/

void solve()
{
	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (i - j >= 0)
			{
				dp[i] += dp[i - j];
				if (dp[i] >= mod)
					dp[i] -= mod;
			}
			else
				break;
		}
	}
	cout << dp[n] << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
