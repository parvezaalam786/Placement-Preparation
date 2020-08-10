/*
https://www.codechef.com/problems/KANYASAI
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> num;
ll L, R;

ll dp[20][20][20][2];

ll DP(int pos, int cnt_5, int cnt_7, int flag)
{
	if (pos == num.size())
	{
		if ((cnt_5 % 2 == 1) && (cnt_7 % 2 == 1))
			return 1;
		else
			return 0;
	}
	if (dp[pos][cnt_5][cnt_7][flag] != -1)
		return dp[pos][cnt_5][cnt_7][flag];

	ll res = 0;
	int limit = 9;
	if (flag == 0)
	{
		limit = num[pos];
	}
	for (int i = 0; i <= limit; i++)
	{
		int new_flag = flag;
		int c5 = cnt_5;
		int c7 = cnt_7;
		if (flag == 0 && i < limit)
			new_flag = 1;
		if (i == 5)
		{	c5 += 1;
		}
		if (i == 7)
		{	c7 += 1;
		}
		res += DP(pos + 1, c5, c7, new_flag);
	}
	dp[pos][cnt_5][cnt_7][flag] = res;
	return res;
}

ll solve(ll n)
{
	num.clear();
	if (n == 0) num.push_back(0);
	while (n > 0)
	{
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(num.begin(), num.end());
	// for (auto i: num)
	//     cout << i << ' ';
	// cout << endl;
	memset(dp, -1, sizeof(dp));
	ll res = DP(0, 0, 0, 0);
	return res;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> L >> R;
		ll ans = solve(R) - solve(L - 1);
		cout << ans << "\n";
	}
	return 0;
}