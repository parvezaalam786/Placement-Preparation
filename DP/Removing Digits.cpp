#include<bits/stdc++.h>
using namespace std;
/*
1. dp[i] = minimum no of steps needed to go from i to 0
2. dp[n] = our answer
3. dp[n] = 1+dp[n-di] where di is the digits in n and n-di>=0
4. Base case: dp[0] = 0
*/

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		int minSteps = 1e6 + 2;
		while (temp != 0)
		{
			int di = temp % 10;
			temp = temp / 10;
			if (di == 0) continue;
			minSteps = min(minSteps, dp[i - di] + 1);
		}
		dp[i] = minSteps;
	}
	cout << dp[n] << "\n";
	return 0;
}


/*This also works (Greedy)
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	while (n != 0)
	{
		int num = n;
		int d_max = 0;
		while (num > 0)
		{
			d_max = max(d_max, num % 10);
			num = num / 10;
		}
		n = n - d_max;
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}*/