/*
https://cses.fi/problemset/task/1636/

Top down takes more memory in recursion calls, therefore it is given RE.

*/
/*
dp[i][x] = represents valid ways to make a change of x using the forst i coins

dp[n][sum] will be our final answer

Recurrence Relation: If we observe carefully it is an unbounded knapsack.
Either we will not take the coin or will we will take it.If we take it we will
still be left with i coins as it has infinite supply.

dp[i][x] = dp[i-1][x] + dp[i][x-coins[i]]

Base case:
	if sum == 0:
		return 1 (by not taking any coins)


*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[501][1000010];
int fun(int coins[], int n, int sum)
{
	//filling base case

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (j >= coins[i - 1])
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i - 1]]) % mod;
			}
			else
				dp[i][j] = dp[i - 1][j] % mod;
		}
	}
	return dp[n][sum];
}

void solve()
{
	int n, sum;
	cin >> n >> sum;

	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sum; j++)
			dp[i][j] = 0;
	int ans = fun(coins, n, sum);
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
