#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
char arr[100];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 0; i <= n; i++)
	{
		dp[0][i] = dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (arr[j] == arr[j - i + 1] and dp[i - 2][j - 1] == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}