#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int SubsetSum(int arr[], int n, int sum)
{
	if (sum == 0)
		return 1;
	if (n < 0 || sum < 0)
		return 0;
	if (dp[n][sum] != -1)
		return dp[n][sum];

	dp[n][sum] = SubsetSum(arr, n - 1, sum - arr[n]) || SubsetSum(arr, n - 1, sum);

	if (dp[n][sum] == 1)
		return 1;

	return 0;
}

int main()
{
	int arr[] = {3, 4, 6, 1, 9};

	int n = sizeof(arr) / sizeof(int);

	int sum = 10;

	memset(dp, -1, sizeof(dp));

	if (SubsetSum(arr, n - 1, sum))
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";

	return 0;
}
