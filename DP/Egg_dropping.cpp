#include<bits/stdc++.h>
using namespace std;

int dp[52][52];

int eggDrop(int e, int f)
{
	if (f == 0 || f == 1)
		return f;
	if (e == 1)
		return f;

	if (dp[e][f] != -1)
		return dp[e][f];

	int mn = INT_MAX;
	for (int k = 1; k <= f; k++)
	{
		int l, r;
		if (dp[e - 1][k - 1] != -1)
			l = dp[e - 1][k - 1];
		else
		{
			l = eggDrop(e - 1, k - 1);
			dp[e - 1][k - 1] = l;
		}
		if (dp[e][f - k] != -1)
			r = dp[e][f - k];
		else
		{
			r = eggDrop(e, f - k);
			dp[e][f - k] = r;
		}

		int temp = 1 + max(l, r);
		mn = min(mn, temp);
	}
	return dp[e][f] = mn;
}


int main()
{
	int f, e;
	cin >> e >> f;
	memset(dp, -1, sizeof(dp));
	cout << eggDrop(e, f) << "\n";

	return 0;
}#include<bits/stdc++.h>
using namespace std;

int dp[52][52];

int eggDrop(int e, int f)
{
	if (f == 0 || f == 1)
		return f;
	if (e == 1)
		return f;

	if (dp[e][f] != -1)
		return dp[e][f];

	int mn = INT_MAX;
	for (int k = 1; k <= f; k++)
	{
		int l, r;
		if (dp[e - 1][k - 1] != -1)
			l = dp[e - 1][k - 1];
		else
		{
			l = eggDrop(e - 1, k - 1);
			dp[e - 1][k - 1] = l;
		}
		if (dp[e][f - k] != -1)
			r = dp[e][f - k];
		else
		{
			r = eggDrop(e, f - k);
			dp[e][f - k] = r;
		}

		int temp = 1 + max(l, r);
		mn = min(mn, temp);
	}
	return dp[e][f] = mn;
}


int main()
{
	int f, e;
	cin >> e >> f;
	memset(dp, -1, sizeof(dp));
	cout << eggDrop(e, f) << "\n";

	return 0;
}