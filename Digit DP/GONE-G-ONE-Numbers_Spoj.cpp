#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
/*
We only have maximum 8 digits in the question and their
sum can be max of 9*8 = 72.

*/
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};
int dp[10][80][2]; //states are pos, sum, tight

bool check(int sum) // if the digit sum is prime
{
	for (int x : primes)
	{
		if (x == sum)
			return true;
	}
	return false;
}


//first number will always be under restriction so tight = 1
int fun(string str, int pos = 0, int sum = 0, int tight = 1)
{
	if (pos == str.length())
	{
		if (check(sum))
			return 1;
		else
			return 0;
	}
	else if (dp[pos][sum][tight] != -1)
		return dp[pos][sum][tight];
	else if (tight == 1)
	{
		int res = 0;
		for (int i = 0; i <= str[pos] - '0'; i++)
		{
			if (i == str[pos] - '0')
				res += fun(str, pos + 1, sum + i, 1);
			else
				res += fun(str, pos + 1, sum + i, 0);
		}
		dp[pos][sum][tight] = res;
		return res;
	}
	else if (tight == 0)
	{
		int res = 0;
		for (int i = 0; i <= 9; i++)
		{
			res += fun(str, pos + 1, sum + i, 0);
		}
		dp[pos][sum][tight] = res;
		return res;
	}
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		/*
			Whenever we are solving questions of digit dp we need to convert the number
			into a format as vectors or string.
		*/
		a = a - 1;

		string l = to_string(a);
		string r = to_string(b);

		memset(dp, -1, sizeof(dp));
		int right = fun(r);
		memset(dp, -1, sizeof(dp));
		int left = fun(l);
		cout << right - left << "\n";

	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
