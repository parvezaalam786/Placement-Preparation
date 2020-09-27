#include<bits/stdc++.h>
using namespace std;

int dp[50][50];

int solve(int arr[], int i, int j)
{
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int mn = INT_MAX;

	for (int k = i; k < j; k++)
	{
		int ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		mn = min(ans, mn);
	}
	return dp[i][j] = mn;
}


int main()
{
	int arr[] = {10, 100, 20, 5, 80};
	int n = 5;
	memset(dp, -1, sizeof(dp));
	int ans = solve(arr, 1, n - 1);
	cout << ans << "\n";
	return 0;
}

//op = 19000