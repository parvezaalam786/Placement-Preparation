/*
Chase excellence, rating will come automatically.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007

bool fun(string fs, string ss, string is, unordered_map<string, bool> &dp)
{
    if (fs.empty() and ss.empty() and is.empty())
        return true;
    if (is.empty())
        return false;

    string ans = fs + "-" + ss + "-" + is;
    if (dp.count(ans))
        return dp[ans];

    bool first = (!fs.empty() and fs[0] == is[0]) and fun(fs.substr(1), ss, is.substr(1), dp);

    bool second = (!ss.empty() and ss[0] == is[0]) and fun(fs, ss.substr(1), is.substr(1), dp);

    return dp[ans] = (first or second);
}

void solve()
{
    string fs, ss, is;
    cin >> fs >> ss >> is;
    unordered_map<string, bool> dp;
    cout << fun(fs, ss, is, dp) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
aabcc
dbbca
aadbbcbcac

1

aabcc
dbbca
aadbbbaccc

0
*/