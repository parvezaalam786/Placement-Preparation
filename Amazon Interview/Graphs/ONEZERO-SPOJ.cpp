// https://www.spoj.com/problems/ONEZERO/
/*
Problem
Certain positive integers have their decimal representation consisting only of ones and zeros,
and having at least one digit one, e.g. 101. If a positive integer does not have such a property,
one can try to multiply it by some positive integer to find out whether the product has this property.
*/
/**
*Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*Love the music of silence.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
#define deb(x) cout<<#x<<" = "<<x
#define all(x) (x).begin(),(x).end()

string multiple(int A)
{
	if (A == 1)
		return "1";
	vector<string> dp(A + 1);
	dp[1] = "1";

	queue<int> que;
	que.push(1);
	while (!que.empty())
	{
		int rem = que.front();
		que.pop();

		if (rem == 0)
			return dp[rem];

		for (int i : {0, 1})
		{
			int new_rem = (rem * 10 + i) % A;
			if (dp[new_rem].empty())
			{
				que.push(new_rem);
				dp[new_rem] = dp[rem] + char('0' + i);
			}
		}
	}
	assert(false);
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << multiple(N) << "\n";
	}

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
