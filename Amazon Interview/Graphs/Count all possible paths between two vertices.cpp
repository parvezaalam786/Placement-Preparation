/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
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

const int maxn = 10005;
int total_paths = 0;
vector<int> adj[maxn];

void dfs(int src, int dest)
{
    if (src == dest)
    {
        total_paths++;
        return;
    }
    else
    {
        for (auto child : adj[src])
        {
            dfs(child, dest);
        }
    }
}
void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0, u, v; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int src, dest;
    cin >> src >> dest;
    dfs(src, dest);
    cout << total_paths << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
5 7
1 2
1 3
1 4
2 4
3 4
2 5
3 5
1 4

3
*/