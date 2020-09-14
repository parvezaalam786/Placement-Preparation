/*
Chase excellence, rating will come automatically.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

unordered_map<string, bool> dp;

bool fun(string& str, string& pat, int s, int p)
{
    string ans = to_string(s) + "-" + to_string(p);
    if (dp.count(ans))
        return dp[ans];
    if (p == pat.length())
    {
        return dp[ans] = (s == str.length());
    }
    if (s == str.length())
    {
        for (int i = p; i < pat.length(); i++)
            if (pat[i] != '*')
                return (dp[ans] = false);
        return (dp[ans] = true);
    }

    if (pat[p] == '?' or pat[p] == str[s])
    {
        return dp[ans] = fun(str, pat, s + 1, p + 1);
    }
    if (pat[p] == '*')
    {
        return dp[ans] = (fun(str, pat, s, p + 1) or fun(str, pat, s + 1, p));
    }
    return false;
}

void solve()
{
    string  str, pat;
    cin >> str >> pat;

    cout << fun(str, pat, 0, 0);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
