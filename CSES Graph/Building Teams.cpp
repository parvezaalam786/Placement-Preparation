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
Here we just have to check if the graph is bipartite or not.
If yes then print the color of each node.
*/


const int maxn = 100005;
vector<int> adj[maxn];
vector<int> color(maxn, -1);
vector<bool> visited(maxn, false);

bool dfs(int src, int col = 0)
{
    bool res = true;
    visited[src] = true;
    color[src] = col;
    for (auto child : adj[src])
    {
        if (visited[child] == false)
        {
            res &= dfs(child, col ^ 1);
        }
        else if (color[src] == color[child])
        {
            res = false;
            break;
        }
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool res = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            res &= dfs(i);
        }
    }
    if (res)
    {
        for (int i = 1; i <= n; i++)
            cout << color[i] + 1 << " ";
    }
    else
        cout << "IMPOSSIBLE" << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
