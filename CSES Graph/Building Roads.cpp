/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

/*
The idea here is same as counting the number of connected components.
*/


const int maxn = 100005;
vector<int> adj[maxn];
vector<bool> visited(maxn, false);

void dfs(int src)
{
    visited[src] = true;
    for (auto child : adj[src])
    {
        if (visited[child] == false)
            dfs(child);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << "\n";

    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
