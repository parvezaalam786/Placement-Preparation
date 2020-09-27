#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 998244353
#define endl "\n"
#define ff first
#define ss second

const int maxn = 300005;
vector<int> adj[maxn];
int col[maxn], vis[maxn];
int cnt0, cnt1;

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % mod;
        }
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

int dfs(int node, int c)
{
    vis[node] = true;
    if (c == 0)
        cnt0++;
    else
        cnt1++;
    col[node] = c;

    for (int child : adj[node])
    {
        if (vis[child] == 0)
        {
            int bipartite = dfs(child, c ^ 1);

            if (bipartite == -1)
                return -1;
        }
        else
        {
            if (col[child] == col[node])
                return -1;
        }
    }
    return 1;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, a, b;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int res = 1;
        bool flag = true; // the ans exists

        //test for each connected component
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                cnt0 = cnt1 = 0;
                int bipartite = dfs(i, 0); //passing node and color
                if (bipartite == -1)
                {
                    flag = false;
                    break;
                }
                res = (res * (power(2, cnt0) + power(2, cnt1))) % mod;
            }
        }
        if (flag)
            cout << res << "\n";
        else
            cout << 0 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
