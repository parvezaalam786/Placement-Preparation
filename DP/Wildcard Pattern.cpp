#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define MAXN 100010
#define mod 1000000007

bool strmatch(char str[], char pattern[], int n, int m)
{
    if (m == 0)
        return (n == 0);
    bool lookup[n + 1][m + 1];
    memset(lookup, false, sizeof(lookup));

    lookup[0][0] = true;

    for (int j = 1; j <= m; j++)
    {
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j - 1] == '*')
                lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];
            else
                lookup[i][j] = false;
        }
    }
    return lookup[n][m];
}
void solve()
{
    char str[1001], pattern[1001];
    cin >> str >> pattern;
    int n = strlen(str);
    int m = strlen(pattern);
    if (strmatch(str, pattern, n, m))
        cout << "MATCHED" << "\n";
    else
        cout << "NOT MATCHED" << "\n";
}

int main()
{
    // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();
    return 0;
}