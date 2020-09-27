#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		int arr[1010];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		bool dp[1010][1024];
		memset(dp, false, sizeof(dp));

		// a single element can have xor equal to itself
		dp[0][0] = dp[0][arr[0]] = 1;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 1024; j++)
			{
				dp[i][j] = dp[i - 1][j] | dp[i - 1][j ^ arr[i]];
			}
		}

		int ans = 0;
		for (int i = 0; i < 1024; i++)
		{
			if (dp[n - 1][i])
			{
				ans = max(ans, k ^ i);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}