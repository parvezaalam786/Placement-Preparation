/*
https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/description/
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
	Basically we have to find the count of numbers which are having as digit 3 as one if theier digits
	and subtract it from the given number.

	flag = 0 means digit 3 is absent else present.
*/

int dp[11][2][2]; //position, tight, flag

int fun(string str, int pos = 0, int tight = 1, int flag = 0)
{
	if (pos == str.length())
	{
		if (flag == 1)
			return 1;
		else
			return 0;
	}
	else if (dp[pos][tight][flag] != -1)
		return dp[pos][tight][flag];
	else if (tight == 1)
	{
		int res = 0;
		for (int i = 0; i <= str[pos] - '0'; i++)
		{
			int flag1 = flag;
			if (i == 3)
				flag1 = 1;
			if (i == str[pos] - '0')
				res += fun(str, pos + 1, 1, flag1);
			else
				res += fun(str, pos + 1, 0, flag1);
		}
		return dp[pos][tight][flag] = res;
	}
	else
	{
		int res = 0;
		for (int i = 0; i <= 9; i++)
		{
			int flag1 = flag;
			if (i == 3)
				flag1 = 1;

			res += fun(str, pos + 1, 0, flag1);
		}
		return dp[pos][tight][flag] = res;
	}
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string str = to_string(n);
		memset(dp, -1, sizeof(dp));
		int x = fun(str);
		cout << n - x << "\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
