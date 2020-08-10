/*
https://cses.fi/problemset/task/1158
*/

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define endl "\n"
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1e18
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007

int fun(int n, int prices[], int pages[], int x)
{
	int dp[n + 1][x + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (prices[i - 1] <= j)
			{
				dp[i][j] = max(dp[i - 1][j], pages[i - 1] + dp[i - 1][j - prices[i - 1]]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][x];
}

void solve()
{
	int n, x;
	cin >> n >> x;
	int prices[n], pages[n];
	F(i, 0, n) cin >> prices[i];
	F(i, 0, n) cin >> pages[i];

	int ans = fun(n, prices, pages, x);
	cout << ans << "\n";

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	// freopen("Test.txt","r",stdin);
	// freopen("Output.txt","w",stdout);
#endif

	// if(debug){watch_is();}
	solve();
	return 0;
}