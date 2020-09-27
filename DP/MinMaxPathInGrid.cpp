#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007

int arr[50][50], dp[50][50];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        dp[n + 1][i] = inf;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][m + 1] = inf;
    }
    dp[n + 1][m] = dp[n][m + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp[i][j] = arr[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


/*
input:
3 4
5 1 2 6
9 9 7 5
3 1 4 8
output:
27 22 21 19
25 22 19 13
16 13 12 8
*/